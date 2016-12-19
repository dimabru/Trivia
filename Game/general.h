#define _CRT_SECURE_NO_WARNINGS
#ifndef _general
#define _general
#include <stdio.h>
#include <string.h>

typedef enum {student,editor,guide} type;

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

//if user is not student, GP=AVG=HS=-1, scoreList=NULL
typedef struct{
	char *firstName, *lastName, *ID, *password;
	type userType;
	int gamesPlayed,average,highScore,*scoreList;
}user;

typedef struct{
	char *ID, *msg;
}message;

typedef struct{
	char *str,*answer;
	int ID, level ,answered; //0 if not answered, 1 if answered
}question;

typedef struct{
	int ID;
	char **fakeList;
}fakeAnswer;

typedef struct{
	int bestResult;
	char* ID;
}best;

#endif