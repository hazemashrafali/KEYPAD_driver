/*
 * Keypad.h
 *
 *  Created on: Feb 18, 2022
 *      Author: HAZEM-PC
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

/* Keypad configurations for number of rows and columns */
#define keypad_no_of_colums     3
#define keypad_no_of_rows       4

/* Keypad Port Configurations */
#define keypad_port_id         PORTB
#define first_row_pinno        PIN0
#define first_colum_pinno      PIN4

/* Keypad button logic configurations */
#define keypad_button_pressed  LOW
#define keypad_button_released HIGH

/*
 * Description :
 * Get the Keypad pressed button
 */
unsigned char keypad_getkey(void);

#endif /* KEYPAD_H_ */
