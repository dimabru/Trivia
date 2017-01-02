#define _CRT_SECURE_NO_WARNINGS
#ifndef _general
#define _general
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "time_calculate.h"
#include "play.h"
#include "guide.h"

typedef enum {student,editor,guide} type;

//if user is not student, GP=AVG=HS=-1, scoreList=NULL
typedef struct{
	char *firstName, *lastName, *ID, *password;
	type userType;
	int gamesPlayed, average, highScore, *scoreList;
}user;

typedef struct{
	char *ID, *msg;
}message;

typedef struct{
	char *str, *answer;
	int ID, level, answered; //0 if not answered, 1 if answered
}question;

typedef struct{
	int ID;
	char **fakeList;
}fakeAnswer;

typedef struct{
	int bestResult;
	char* ID;
}best;

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

int whileNotInt(char* str)
{
	int num = inputCheck(str);
	char *arr=(char*)malloc(sizeof(1));
	while (num == -1)
	{
		printf("Try again. Wrong input\n");
		scanf("%s", arr);
		num = inputCheck(arr);
	}
	free(arr);
	return num;
}

int rUsure()
{
	char x;
	while (1)
	{
		printf("Are you sure? (enter y if yes, n if no)\n");
		scanf("%c", &x);
		if (x == 'y' || x == 'Y') return 1;
		if (x == 'n' || x == 'N') return 0;
		printf("Wrong input. Try again\n");
		fflush(stdin);
	} 
}



#endif