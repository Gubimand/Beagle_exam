/*
 * buffer.h
 *
 *  Created on: 30 Dec 2019
 *      Author: jinxluck
 */

//struct to import to main:
/*
struct buffer
{
	int number;
	int data;
	struct buffer *next;
}return_struct;
 */

#ifndef BUFFER_H_
#define BUFFER_H_

//Function to insert integers into the buffer, on space at the time.
//The buffer returns 1 if successful.
//The buffer returns 0 if not successful.
int buffer_input(int input);

//returns a struct.
//if end pointer is reached, it will continue to return the end struct.
struct buffer buffer_output(void);

#endif /* BUFFER_H_ */
