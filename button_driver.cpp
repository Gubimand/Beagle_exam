/*
 * button_driver.cpp
 *
 *  Created on: 30 Dec 2019
 *      Author: jinxluck
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "button_driver.h"

using namespace std;

//btn's for binary number, and controlling the program.
//char button : port
char btn_next[] = {"45"};
char btn_done[] = {"52"};

struct buttons
{
	char next[5];
	char done[5];
}vals;

//port set
void PS(char *port)
{
	FILE *fs;

	char gpio_direction[100] = "/sys/class/gpio/gpio";
	strcat(gpio_direction, port);
	strcat(gpio_direction,"/direction");

	fs=fopen(gpio_direction,"w");

	fseek(fs,0,SEEK_SET);
	fprintf(fs,"in");
	fclose(fs);
}


//port read
char * PR(char *port)
{
	FILE *fs;
	char buff[10];
	buff[0] = '\0';

	char gpio_direction[100] = "/sys/class/gpio/gpio";
	strcat(gpio_direction, port);
	strcat(gpio_direction,"/value");

	fs=fopen(gpio_direction,"r");

	fseek(fs,0,SEEK_SET);

	fgets(buff, 10, (FILE*)fs);

	return buff;
}

int init_buttons(void)
{
	cout<<"init buttons"<<endl;
	PS(btn_next);
	PS(btn_done);

	return 1;
}

struct buttons read_buttons(void)
{
	struct buttons *temp;

	temp = (struct buttons*)malloc(sizeof(struct buttons));

	strcpy(temp->done,PR(btn_done));
	strcpy(temp->next,PR(btn_next));

	return *temp;
}













