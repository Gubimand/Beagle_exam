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
	char * data;
	struct buffer *next;
}return_struct;
 */

#include <string.h>

#ifndef BUFFER_H_
#define BUFFER_H_

const int BUFFERSIZE = 3;
const int INPUT_SIZE = 20;

//Function to insert integers into the buffer, on space at the time.
//The buffer returns 1 if successful.
//The buffer returns 0 if not successful.
int buffer_input(char input[INPUT_SIZE]);

//returns a struct.
//if end pointer is reached, it will continue to return the end struct.
struct buffer buffer_output(void);

void runthrough(void);

#endif /* BUFFER_H_ */
