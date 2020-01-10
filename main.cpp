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

	for(i= 0; x[i]!=0; i++)
		LCD_DATA(x[i]);

	while(1){
		sleep(2);
		LCD_CLEAR();
		buttons = read_buttons();


		if(buttons.done[0] == '1'){
			char high[] = "High";

			for(i= 0; high[i]!=0; i++)
				LCD_DATA(high[i]);
		}
		else{
			char Low[] = "Low";

			for(i= 0; Low[i]!=0; i++)
				LCD_DATA(Low[i]);
		}
	}


	return 0;
}



