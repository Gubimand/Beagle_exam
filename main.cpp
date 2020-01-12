////////////////////////////////////////////////////////////
//
// Source file : 	main.cpp
// Author :			malthe
// Date :			Jan 10, 2020
// Version :
//
// Description :
//
////////////////////////////////////////////////////////////

#include "lcd_driver.h"
#include "buffer.h"
#include "button_driver.h"

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

using namespace std;

/**
 *
 */
struct buttons
{
	char bin1[5];
	char bin2[5];
	char next[5];
	char done[5];
}buttons;

struct buffer
{
	int number;
	char * data;
	struct buffer *next;
}return_struct;

void NEXT_DATA(void){
	int i = 0;

	LCD_CLEAR();
	return_struct = buffer_output();
	cout<<return_struct.data<<return_struct.number<<endl;

	for(i= 0; return_struct.data[i]!=0; i++)
					LCD_DATA(return_struct.data[i]);
}

int INIT(void){

	if( LCD_INIT() !=1){
		cout<<"Error in init of display"<<endl;
		return -1;
	}

	if(init_buttons() !=1){
		cout<<"Error in init of buttons"<<endl;
		return -1;
	}

	return 0;
}

/**
 *
 * @return
 */
int main(void){

	int i = 0;
	char x[] = "Welcome!";


	//Intiates all functions
	if(INIT() == -1)
		return -1;

	for(i = 0; x[i]!=0; i++)
		cout<<"Welcome"<<endl;
		LCD_DATA(x[i]);

	for(i = 0; i<=BUFFERSIZE;i++){
		char input[INPUT_SIZE];
		cin>>input;
		buffer_input(input);
	}

	while(1){
		cout<<
		sleep(2);

		buttons = read_buttons();


		if(buttons.done[0] == '1'){
			NEXT_DATA();
		}
	}


	return 0;
}



