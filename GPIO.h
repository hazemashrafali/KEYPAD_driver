/*
 * GPIO.h
 *
 *  Created on: Feb 17, 2022
 *      Author: HAZEM-PC
 */

#ifndef GPIO_H_
#define GPIO_H_

#define PORTA ((volatile unsigned char*)0x39)
#define PORTB ((volatile unsigned char*)0x36)
#define PORTC ((volatile unsigned char*)0x33)
#define PORTD ((volatile unsigned char*)0x30)

#define OUTPUT 1
#define INPUT 0

#define PORT_OUTPUT 0xFF
#define PORT_INPUT  0x00

#define HIGH 1
#define LOW 0

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

typedef struct portname{
	char pinx;
	char ddrx;
	char portx;
}Sportname;

typedef struct pinconf{
	Sportname *PPortx;
	char pin_no;
	char dir;
	char val;
}Spinconf;

typedef struct portconf{
	Sportname *PPortx;
	char dir;
	char val;
}Sportconf;


void set_direction(Spinconf port);
void write_pin(Spinconf port);
char read_pin(Spinconf port);
void set_port_direction(Sportconf port);
void write_port(Sportconf port);
char read_port(Sportconf port);
void pinMode(int pin,char state);

#endif /* GPIO_H_ */
