#define _CRT_SECURE_NO_WARNINGS
#ifndef _general
#define _general
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


typedef enum { student, editor, guide } type;

//if user is not student, GP=AVG=HS=-1, scoreList=NULL
typedef struct{
	char firstName[80], lastName[80], ID[11], password[80];
	type userType;
	int gamesPlayed, average, highScore, *scoreList;
}user;

typedef struct{
	char ID[11], msg[6400];
}message;

typedef struct{
	char str[6400], answer[80];
	int ID, level, answered; //0 if not answered, 1 if answered
}question;

typedef struct{
	int ID,fakeAmount;
	char fakeList[80][80];
}fakeAnswer;

typedef struct{
	int bestResult;
	char ID[11];
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

void printUser(user unit)
{
	char *x;
	int i;
	if (unit.userType == 0) x = "student";
	else if (unit.userType == 1) x = "editor";
	else x = "guide";
	printf("first name: %s\n", unit.firstName);
	printf("last name: %s\n", unit.lastName);
	printf("ID: %s\n", unit.ID);
	printf("password: %s\n", unit.password);
	printf("user type: %s\n", x);
	if (unit.userType == student)
	{
		printf("games played: %d\n", unit.gamesPlayed);
		printf("average: %d\n", unit.average);
		printf("high score: %d\n", unit.highScore);
		if (unit.gamesPlayed)
		{
			printf("Score List:\n");
			for (i = 0; i < unit.gamesPlayed; i++) printf("%d) %d\n", i + 1, unit.scoreList[i]);
		}
	}
}

user searchUser(char *id)
{
	//int i,size=0;
	//user error,*list = getUsers(&size);
	//error.average = -1;
	//for (i = 0; i < size; i++)
	//{
	//	if (!strcmp(list[i].ID, id)) return list[i];
	//}
	//return error;
}

void addUser(user newUser)
{
	//int size;
	//user *list = getUsers(&size);
	//list = (user*)realloc(list, size + 1);
	//list[size] = newUser;
	//setUsers(list, size + 1);
	return;
}

#endif