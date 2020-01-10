/*
 * buffer.cpp
 *
 *  Created on: 30 Dec 2019
 *      Author: jinxluck
 */

#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"

int BUFFER_SIZE = 3;

struct buffer
{
	int number;
	int data;
	struct buffer *next;
};

struct buffer *pointer_in = NULL;
struct buffer *pointer_out = NULL;
struct buffer *start = NULL;
struct buffer *end = NULL;

int buffer_input(int input)
{
	static int count_in = 1;

	if(count_in<=BUFFER_SIZE)
	{
		struct buffer *temp;


		temp = (struct buffer*)malloc(sizeof(struct buffer));

		if(start == NULL)
		{
			start = temp;
			start->number=count_in;
			start->data=input;
			start->next=NULL;
			count_in++;
			return 1;
		}

		if(count_in==BUFFER_SIZE)
		{
			pointer_in=start;

			while(pointer_in->next != NULL)
				pointer_in = pointer_in->next;

			pointer_in->next=temp;
			temp->number=count_in;
			temp->data=input;
			temp->next=start;
			end = temp;
			count_in++;
			return 1;
		}

		pointer_in=start;

		while(pointer_in->next != NULL)
			pointer_in = pointer_in->next;

		pointer_in->next=temp;
		temp->number=count_in;
		temp->data=input;
		temp->next=NULL;

		count_in++;

		return 1;
	}
	else
		return 0;
}

struct buffer buffer_output(void)
{
	static int count_out = 1;
	int i = 0;

	pointer_out = start;
	int temp = pointer_out->number;


	if(temp == count_out)
	{
		count_out++;
		return *pointer_out;
	}
	else
	{
		while(temp != count_out)
		{
			pointer_out = pointer_out->next;
			temp = pointer_out->number;

			//failsafe
			i++;
			if(i > 10)
				return *end;
		}
	}
	count_out++;
	return *pointer_out;
}


