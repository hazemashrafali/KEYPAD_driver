/*
 * Keypad.c
 *
 *  Created on: Feb 18, 2022
 *      Author: HAZEM-PC
 */

#include "common_macros.h"
#include "Keypad.h"
#include "GPIO.h"

#if (keypad_no_of_colums == 4)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x4 keypad
 */
static unsigned char KEYPAD_4x4_adjustKeyNumber(unsigned char button_number);
#elif (keypad_no_of_colums == 3)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x3 keypad
 */
static unsigned char KEYPAD_4x3_adjustKeyNumber(unsigned char button_number);
#endif

unsigned char keypad_getkey(void)
{
	unsigned char row=0,col=0;
	Sportconf keypad_port={keypad_port_id};
	Spinconf srow={keypad_port_id},scol={keypad_port_id};

	while(1)
	{
		for(col=0;col<keypad_no_of_colums;col++)  /* loop for columns */
		{
			/*
			 * Each time setup the direction for all keypad port as input pins,
			 * except this column will be output pin
			 */
			keypad_port.dir=PORT_INPUT;
			set_port_direction(keypad_port);
			scol.dir=OUTPUT;
			scol.pin_no=first_colum_pinno+col;
			set_direction(scol);
#if(keypad_button_pressed == LOW)
			/* Clear the column output pin and set the rest pins value */
			keypad_port.val = ~(1<<(first_colum_pinno+col));
#else
			/* Set the column output pin and clear the rest pins value */
			keypad_port.val = (1<<(first_colum_pinno+col));
#endif
			write_port(keypad_port);
			for(row=0;row<keypad_no_of_rows;row++)  /* loop for rows */
			{
				srow.pin_no=first_row_pinno+row;
				if(read_pin(srow)==keypad_button_pressed)
				{
#if (keypad_no_of_colums == 4)
					return KEYPAD_4x4_adjustKeyNumber((row*keypad_no_of_colums)+col+1);
#elif (keypad_no_of_colums == 3)
					return KEYPAD_4x3_adjustKeyNumber((row*keypad_no_of_colums)+col+1);
#endif
				}
			}
		}
	}
}

#if (keypad_no_of_colums == 3)
/*
 * Description :
 * Update the keypad pressed button value with the correct one in keypad 4x3 shape
 */
static unsigned char KEYPAD_4x3_adjustKeyNumber(unsigned char button_number)
{
	unsigned char keypad_button = 0;
	switch(button_number)
	{
		case 10: keypad_button = '*'; // ASCII Code of *
				 break;
		case 11: keypad_button = 0;
				 break;
		case 12: keypad_button = '#'; // ASCII Code of #
				 break;
		default: keypad_button = button_number;
				break;
	}
	return keypad_button;
}
#elif (keypad_no_of_colums==4)
/*
 * Description :
 * Update the keypad pressed button value with the correct one in keypad 4x4 shape
 */
static unsigned char KEYPAD_4x4_adjustKeyNumber(unsigned char button_number)
{
	unsigned char keypad_button = 0;
	switch(button_number)
	{
		case 1: keypad_button = 7;
				break;
		case 2: keypad_button = 8;
				break;
		case 3: keypad_button = 9;
				break;
		case 4: keypad_button = '%'; // ASCII Code of %
				break;
		case 5: keypad_button = 4;
				break;
		case 6: keypad_button = 5;
				break;
		case 7: keypad_button = 6;
				break;
		case 8: keypad_button = '*'; /* ASCII Code of '*' */
				break;
		case 9: keypad_button = 1;
				break;
		case 10: keypad_button = 2;
				break;
		case 11: keypad_button = 3;
				break;
		case 12: keypad_button = '-'; /* ASCII Code of '-' */
				break;
		case 13: keypad_button = 13;  /* ASCII of Enter */
				break;
		case 14: keypad_button = 0;
				break;
		case 15: keypad_button = '='; /* ASCII Code of '=' */
				break;
		case 16: keypad_button = '+'; /* ASCII Code of '+' */
				break;
		default: keypad_button = button_number;
				break;
	}
	return keypad_button;
}
#endif

