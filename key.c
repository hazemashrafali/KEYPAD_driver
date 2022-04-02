/*
 * key.c
 *
 *  Created on: Feb 21, 2022
 *      Author: HAZEM-PC
 */
#include "GPIO.h"

typedef unsigned char uint8;

typedef enum{
	keyLOW,keyHIGH
}button_logic;

typedef struct{
	uint8 rows;					//no of rows
	uint8 cols;					//no of columns
	uint8 *rowpin;			    //row pins
	uint8 *colpin;				//columns pins
	button_logic key;			//define button logic pressed=LOW
}keypad;

void keypad_init(uint8 row,uint8 col,uint8 *rows,uint8 *cols)
{

}
