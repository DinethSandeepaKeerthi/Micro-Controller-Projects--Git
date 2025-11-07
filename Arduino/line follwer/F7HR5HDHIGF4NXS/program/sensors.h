#ifndef sensors
#define sensors

#include <avr/io.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include <pushbutton.h>

#define emitterPORT		PORTC
#define emitterDir		DDRC
#define emitterPIN		PIN6
#define numberOfSensors	8
#define emitters_on()	{									\
							emitterPORT |= 1<<emitterPIN; 	\
							_delay_ms(1);					\
						}
#define emitters_off()	{										\
							emitterPORT &= ~(1<<emitterPIN); 	\
							_delay_ms(1);						\
						}
#define BLACK 		0
#define WHITE 		1
#define line_color 	WHITE
	
void init_sensors(void);
void calibrate_sensors(void);
uint8_t get_sensors_binary(void);
void get_sensors_analog(uint16_t *sensorValues);
uint16_t analog_read(uint8_t inputChannel);
uint8_t count_binary(uint8_t binary);
uint8_t get_front_sensor(void);

static uint16_t maxValues[8], minValues[8], threshold[8];

/*	Intializes 10-bit ADC and sets the emitter pin to output mode.
 *	This fuction should be called before calling any other fuction
 *	in the <sensors.h> library. Prescalar value of 128 is chosen
 *	so as to obtain a sampling rate of 125kHz.
 */
void init_sensors()
{
    ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);	//Sets prescalar as 128 for 125kHz sampling
    ADMUX |= 1<<REFS0;				//Sets reference voltage as AVCC
    ADCSRA |= 1<<ADEN;				//Enable ADC
    emitterDir |= 1<<emitterPIN;	//Sets emitter pin to output mode
}

/*	Maximum and minimum values of each sensor is found using median
 *	filter method and it is stored in an array and it is used to 
 *	obtain the individual threshold.
 */
void calibrate_sensors()
{	
	uint16_t sensorValues[numberOfSensors], temp[100][numberOfSensors], t;
	uint8_t flag = 1, key;
	
	clear_screen();
	print_string(1, 1, "Press any key to");
	print_string(1, 2, "calib. MAX value");
	key = wait_for_button_press();
	clear_screen();
	print_string(2, 1, "Calibrating...");
	for(uint8_t x=0; x<2; x++)
	{	
		//Take 100 readings from 8 sensors and store it into an array
		for(uint8_t k=0; k<100; k++)
		{
			for(uint8_t j=0; j<numberOfSensors; j++)
			{
				emitters_on();		//Set IR emitters on
				temp[k][j] = analog_read(j);
				emitters_off();		//Set IR emitters off
				sensorValues[j] = analog_read(j);
				temp[k][j] = temp[k][j] - sensorValues[j];
			}
		}
		//Arrange the values of each sensor in ascending order
		for(uint8_t k=0; k<numberOfSensors; k++)
		{
			for(uint8_t j=0; j<99; j++)
				for(uint8_t i=j+1; i<100; i++)
					if(temp[i][k] < temp[j][k])		
					{
						t = temp[i][k];
						temp[i][k] = temp[j][k];
						temp[j][k] = t;
					}
			if(flag)
				maxValues[k] = temp[49][k];
			else
				minValues[k] = temp[49][k];
		}
		if(flag)
		{
			clear_screen();
			print_string(1, 1, "Press any key to");
			print_string(1, 2, "calib. MIN value");
			key = wait_for_button_press();
			clear_screen();
			print_string(2, 1, "Calibrating...");
			flag = 0;
		}
	}	
	for(uint8_t i=0; i<numberOfSensors; i++)
	{
		threshold[i] = minValues[i] + ((maxValues[i] - minValues[i]) / 2);
		eeprom_write_word((uint16_t*)(i*2), threshold[i]);
		eeprom_write_word((uint16_t*)((i*2)+16), minValues[i]);
		eeprom_write_word((uint16_t*)((i*2)+32), maxValues[i]);
	}
}

/*	Reads analog values from sensors and converts them into binary.
 *	If the analog value for a sensor is above its threshold, then 
 *	a binary 1 is written. In all other case a binary 0 is written.
 *  If the line color is BLACK, then all the eight bits are complemented.
 */
uint8_t get_sensors_binary()
{
	uint16_t binaryArray[8];
	uint8_t binary=0, bitmask=0b10000000;
	get_sensors_analog(binaryArray);
	for(uint8_t i=0; i<numberOfSensors; i++)
	{
		if(binaryArray[i] > threshold[i])
			binary |= bitmask;
		else
			binary |= 0;
		bitmask = bitmask>>1;
	}
	if(line_color)
		return binary;
	else
		return (binary ^ 0xFF);
}

/*	Reads analog values from the sensors into an array with the
 *	IR emitters in ON state. A second set of sensor readings is
 *	taken with the IR emitters in OFF state. The difference of
 *	the two values is stored in sensorValues.This method of
 *	reading sensors reduces the effect of ambient light.
 */
void get_sensors_analog(uint16_t *sensorValues)
{
	uint16_t temp[numberOfSensors];
	for(uint8_t i=0; i<numberOfSensors; i++)
	{	
		emitters_on();		//Set IR emitters on
		sensorValues[i] = analog_read(i);
		emitters_off();		//Set IR emitters off
		temp[i] = analog_read(i);
		sensorValues[i] -= temp[i];
		if(sensorValues[i] < minValues[i])
			sensorValues[i] = minValues[i];
		else if(sensorValues[i] > maxValues[i])
			sensorValues[i] = maxValues[i];
	}
}

/*	Reads the analog value of the selected channel and returns it.
 *	The function waits until the conversion is complete.
 */
uint16_t analog_read(uint8_t inputChannel)
{
	ADMUX = 0x40;			//Clears the MUX0-MUX4 bits
    ADMUX |= inputChannel;	//Sets the ADC input channel
    ADCSRA |= 1<<ADSC;		//Start the conversion
    while(!(ADCSRA & (1 << ADIF)));	//Wait for conversion to complete
    uint8_t lowerByte = ADCL;
    uint16_t result = ADCH<<8 | lowerByte;
    return result;
}

/*	Counts and returns the number of sensors that are over the line.
 */
uint8_t count_binary(uint8_t binary)
{
	uint8_t bitmask=0b10000000, binaryCount=0;	
	for(uint8_t i=0; i<numberOfSensors; i++)
	{
		if(binary & bitmask)
			binaryCount++;
		bitmask = bitmask>>1;
	}
	return binaryCount;
}

/*	Reads the state of the front sensor. Return a '1' 
 *	if it is over the line, otherwise returns a '0'.
 */
uint8_t get_front_sensor()
{
	uint8_t state;
	emitters_on();
	if(bit_is_set(PINC, 7))
		state = line_color;
	else
		state = !line_color;
	emitters_off();
	return state;
	
}
#endif