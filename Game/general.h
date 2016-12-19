#define _CRT_SECURE_NO_WARNINGS
#ifndef _general
#define _general
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef enum {STUDENT,EDITOR,GUIDE} user;

//function receives a string and returns a number if it consists of a positive number
int inputCheck(char* str)
{
	int i,num=0;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] >= '0'&&str[i] <= '9') num = num*10 + str[i] - 48;
		else return -1;
	}
	if (strlen(str) > 10) return -1;
	return num;
}

#endif