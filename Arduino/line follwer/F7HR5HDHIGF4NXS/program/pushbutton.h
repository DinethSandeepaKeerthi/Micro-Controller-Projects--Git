#ifndef pushbutton
#define pushbutton

#include <avr/io.h>
#include <util/delay.h>

#define LEFT_BUTTON		0
#define MIDDLE_BUTTON	1
#define RIGHT_BUTTON	2
#define TOP_BUTTON		3

void init_pushbutton(void);
uint8_t get_single_button_press(void);
uint8_t wait_for_button_press(void);

void init_pushbutton()
{
	//Set left, middle, right and top push button pins to input mode
	DDRC &= ~(1<<PINC0 | 1<<PINC1 | 1<<PINC2 | PINC3);
	//Activate pull up resistors on left, middle, right and top push button pins
	PORTC |= 1<<PINC0 | 1<<PINC1 | 1<<PINC2 | 1<<PINC3;
}

/*	This function checks whether any key is pressed. If it detects ant keypress,
 *	it waits for that particular key to be released and then returns the keycode.
 */
uint8_t get_single_button_press(void)
{
	if(bit_is_clear(PINC, 0))
	{		
		while(bit_is_clear(PINC, 0));	//Wait until the push button is released
		return 0;						//return the push button code
	}
	else if(bit_is_clear(PINC, 1))
	{
		while(bit_is_clear(PINC, 1));
		return 1;
	}
	else if(bit_is_clear(PINC, 2))
	{
		while(bit_is_clear(PINC, 2));
		return 2;
	}
	else if(bit_is_clear(PINC, 3))
	{
		while(bit_is_clear(PINC, 3));
		return 3;
	}
	else
		return 4;
}

/*	This function waits until a key is pressed. Upon detecting
 *	a keypress, it waits for that particular key to be released.
 *	Then it returns the	corresponding keycode.
 */
uint8_t wait_for_button_press(void)
{
	uint8_t button = 4;
	while(1)
	{
		if(bit_is_clear(PINC, 0))
			button = 0;
		else if(bit_is_clear(PINC, 1))
			button = 1;
		else if(bit_is_clear(PINC, 2))
			button = 2;
		else if(bit_is_clear(PINC, 3))
			button = 3;
		if(button < 4)
			break;
	}
	_delay_ms(25);
	while(1)
		if(bit_is_set(PINC, button))
			return button;
}
#endif