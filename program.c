/*
 * program.c
 *
 *  Created on: Feb 18, 2022
 *      Author: HAZEM-PC
 */


#include "GPIO.h"
#include "util/delay.h"
#include "Keypad.h"
int main(void)
{
	char key;
	Sportconf segment={PORTC,PORT_OUTPUT,0xFF};
	set_port_direction(segment);
	while(1)
	{
		key=keypad_getkey();
        segment.val = (key<<4);

	    if((key >= 0) && (key <= 9))
		{
	    	write_port(segment); /* display the key number on the 7-segment */
		}
	}
}
