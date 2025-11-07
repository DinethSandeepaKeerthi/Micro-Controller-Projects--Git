#ifndef lcd
#define lcd

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define _CONCAT(a,b) a##b
#define PORT(x) _CONCAT(PORT,x)
#define PIN(x) _CONCAT(PIN,x)
#define DDR(x) _CONCAT(DDR,x)

#define LCD_DATA 	D	//Port PD0-PD3 are connected to DB4-DB7
#define LCD_E 		B 	//Enable OR strobe signal
#define LCD_RS 		B
#define LCD_RW 		B
#define LCD_RS_POS 	PB0
#define LCD_RW_POS 	PB1
#define LCD_E_POS	PB2	//Position of enable in above port

#define LCD_DATA_PORT 	PORT(LCD_DATA)
#define LCD_E_PORT 		PORT(LCD_E)
#define LCD_RS_PORT 	PORT(LCD_RS)
#define LCD_RW_PORT 	PORT(LCD_RW)

#define LCD_DATA_DDR 	DDR(LCD_DATA)
#define LCD_E_DDR 		DDR(LCD_E)
#define LCD_RS_DDR 		DDR(LCD_RS)
#define LCD_RW_DDR 		DDR(LCD_RW)

#define LCD_DATA_PIN	PIN(LCD_DATA)

#define Set_Enable()	(LCD_E_PORT|=(1<<LCD_E_POS))
#define Set_RS() 		(LCD_RS_PORT|=(1<<LCD_RS_POS))
#define Set_RW() 		(LCD_RW_PORT|=(1<<LCD_RW_POS))
#define Clear_Enable() 	(LCD_E_PORT&=(~(1<<LCD_E_POS)))
#define Clear_RS() 		(LCD_RS_PORT&=(~(1<<LCD_RS_POS)))
#define Clear_RW() 		(LCD_RW_PORT&=(~(1<<LCD_RW_POS)))

#define send_a_command(c) 	(lcd_byte(c,0))
#define send_a_character(d) (lcd_byte(d,1))
#define print_integer		send_an_integer_with_location
#define print_string		send_a_string_with_location
#define lcd_home() 			send_a_command(0b00000010);
#define clear_screen()		{								\
								send_a_command(0b00000001);	\
								_delay_ms(2);				\
							}

void check_if_busy(void);
void lcd_byte(uint8_t,uint8_t);
void init_lcd(void);
void send_a_string(char *StringOfCharacters);
void send_an_integer_with_location(uint8_t x, uint8_t y, int IntegerToDisplay, char NumberOfDigits);
void send_a_string_with_location(uint8_t x, uint8_t y, char *StringOfCharacters);
void print_binary(uint8_t binary);
void goto_location(uint8_t x,uint8_t y);

char firstColumnPostions[2] = {0, 64};

void check_if_busy()
{
	uint8_t busy, status = 0b00000000, temp;

	LCD_DATA_DDR &= 0b11110000;	//Change data port to input

	Set_RW();			//Sets R/W to read mode to read status information
	Clear_RS();			//When RS is low, data read from LCDsCrib indicates its status
	_delay_us(0.5);		//Address set up time (tAS)

	do
	{
		Set_Enable();
		_delay_us(0.5);			//Enable high time (tEH)

		status = LCD_DATA_PIN;	//Higher nibble is stored in 'status'
		status = status<<4;		//Higher nibble is shifted 4 places to the left
		_delay_us(0.5);			//Data access time (tDA)

		Clear_Enable();
		_delay_us(1);			//Enable low time (tEL)

		Set_Enable();
		_delay_us(0.5);			//Enable high time (tEH)

		temp = LCD_DATA_PIN;	//Lower nibble is stored in 'temp'
		temp &= 0b00001111;		//Higher nibble of 'temp' is made zero so that
		status = status|temp;	//OR operation can be performed with 'status'
		busy = status & 0b10000000;
		_delay_us(0.5);
		
		Clear_Enable();
		_delay_us(1);			//Enable low time (tEL)
		
	}while(busy);

	Clear_RW();
	LCD_DATA_DDR |= 0b00001111;	//Change data port back to output
}

void lcd_byte(uint8_t data,uint8_t isdata)
{
	uint8_t higherNibble, lowerNibble;
	uint8_t temp;

	higherNibble = data>>4;
	lowerNibble = (data & 0b00001111);

	if(isdata == 0)
		Clear_RS();
	else
		Set_RS();
	_delay_us(0.500);

	Set_Enable();
	temp = (LCD_DATA_PORT & 0b11110000) | (higherNibble);
	LCD_DATA_PORT = temp;
	_delay_us(1);

	Clear_Enable();
	_delay_us(1);

	Set_Enable();
	temp = (LCD_DATA_PORT & 0b11110000) | (lowerNibble);
	LCD_DATA_PORT = temp;
	_delay_us(1);

	Clear_Enable();
	_delay_us(1);

	check_if_busy();
}

void init_lcd()
{
	_delay_ms(30);
	
	LCD_DATA_DDR |= 0b00001111;		//LCDs data pins(D0-D3) are set to output
	LCD_E_DDR |= 1<<LCD_E_POS;
	LCD_RS_DDR |= 1<<LCD_RS_POS;
	LCD_RW_DDR |= 1<<LCD_RW_POS;

	LCD_DATA_PORT &= 0b11110000; 	//LCDs data pins are pulled
	Clear_Enable();
	Clear_RW();
	Clear_RS();
	_delay_us(0.3);

	Set_Enable();
	LCD_DATA_PORT |= 0b00000010;
	_delay_us(1);
	
	Clear_Enable();
	_delay_us(1);
	
	check_if_busy();

	send_a_command(0b00101000);	
	_delay_us(4.5);
	send_a_command(0b00001100);		//Sets display on, cursor off, cursor to be not blinking
	_delay_us(50);
	send_a_command(0b00000001); 	//Clear Screen 0x01 = 00000001
	_delay_ms(2);
}

void send_a_string(char *StringOfCharacters)
{
	while(*StringOfCharacters > 0)
		send_a_character(*StringOfCharacters++);
}

void send_a_string_with_location(uint8_t x, uint8_t y, char *StringOfCharacters)
{
	goto_location(x, y);
	send_a_string(StringOfCharacters);
}

void send_an_integer_with_location(uint8_t x, uint8_t y, int IntegerToDisplay, char NumberOfDigits)
{
	char StringToDisplay[NumberOfDigits];
	itoa(IntegerToDisplay, StringToDisplay, 10);
	for(int i=0; i<NumberOfDigits; i++)
		send_a_string(" ");
	send_a_string_with_location(x, y, StringToDisplay);
}

void print_binary(uint8_t binary)
{
	uint8_t bitmask=0b10000000;
	for(uint8_t i=0, j=1; i<8; i++, j+=2)
	{
		if(binary & bitmask)
			print_string(j, 2, "1");
		else
			print_string(j, 2, "0");
		bitmask = bitmask>>1;
	}
}

void goto_location(uint8_t x,uint8_t y)
{
	send_a_command(0x80 + firstColumnPostions[y-1] + (x-1));
}
#endif