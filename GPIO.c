/*
 * GPIO.c
 *
 *  Created on: Feb 17, 2022
 *      Author: HAZEM-PC
 */
#include "GPIO.h"
#include "common_macros.h"

void set_direction(Spinconf port)
{
	if(port.dir==0)
	{
		CLEAR_BIT(port.PPortx->ddrx,port.pin_no);
	}
	else
	{
		SET_BIT(port.PPortx->ddrx,port.pin_no);
	}
}

void write_pin(Spinconf port)
{
	if(port.val==0)
	{
		CLEAR_BIT(port.PPortx->portx,port.pin_no);
	}
	else
	{
		SET_BIT(port.PPortx->portx,port.pin_no);
	}
}

char read_pin(Spinconf port)
{
	if(BIT_IS_SET(port.PPortx->pinx,port.pin_no))
		return 1;
	else
		return 0;
}

void set_port_direction(Sportconf port)
{
	port.PPortx->ddrx=port.dir;
}

void write_port(Sportconf port)
{
	port.PPortx->portx=port.val;
}

char read_port(Sportconf port)
{
	return port.PPortx->pinx;
}

void pinMode(int pin,char state)
{
	char *portName;
	if((pin>=0) && (pin<=7))
	{
		portName=((volatile char*)(0x39+1));
	}
	else if((pin>=8) && (pin<=15))
	{
		portName=((volatile char*)(0x36+1));
		pin=pin-8;
	}
	else if((pin>=16) && (pin<=23))
	{
		portName=((volatile char*)(0x33+1));
		pin=pin-16;
	}
	else if((pin>=24) && (pin<=31))
	{
		portName=((volatile char*)(0x30+1));
		pin=pin-24;
	}
	else
	{
	}
	if(state==OUTPUT)
		SET_BIT(*portName,pin);
	else
		CLEAR_BIT(*portName,pin);

}
