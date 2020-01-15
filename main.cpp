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
	char next[5];
	char done[5];
}buttons;

struct buffer
{
	int number;
	char data[INPUT_SIZE];
	struct buffer *next;
}return_struct;

void NEXT_DATA(void){
	int i = 0;

	LCD_CLEAR();
	return_struct = buffer_output();
	cout<<endl<<return_struct.data<<return_struct.number<<endl;

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

	cout<<"Welcome"<<endl;

	for(i = 0; x[i]!=0; i++)
		LCD_DATA(x[i]);

	cout<<"buffer function initiated"<<endl;

	for(i = 0; i<=BUFFERSIZE-1;i++){
		char input[INPUT_SIZE];
		cin>>input;
		buffer_input(input);
	}

	cout<<"buffer runthrough"<<endl;
	runthrough();

	cout<<"button read initiated"<<endl;

	while(1){
		cout<<"new round"<<endl;
		sleep(2);

		buttons = read_buttons();


		if(buttons.done[0] == '1'){
			cout<<"next data"<<endl;

			if(return_struct.number != BUFFERSIZE)
			{
				NEXT_DATA();

			}
			else
			{
			int i = 0;
			char mess[20] = "end of buffer!";

			LCD_CLEAR();

			cout<<"size of mess="<<sizeof(mess)/sizeof(mess[0])<<endl;

			for(i= 0; mess[i]!='\0'; i++)
				LCD_DATA(mess[i]);
			}
		}

		if(buttons.next[0] == '1')
		{
			cout<<"done"<<endl;
			LCD_CLEAR();

			int i = 0;
			char done[20] = "shutting down!";

			for(i= 0; done[i]!='\0'; i++)
				LCD_DATA(done[i]);

			return 0;
		}

	}


	return 0;
}



