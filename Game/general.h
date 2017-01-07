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
	char str[1000], answer[80];
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
long inputCheck(char*);

long whileNotInt(char*);

int rUsure();

void printUser(user);

void printUserList(user*, int);

user searchUser(char*);

void addUser(user);

void addQuestion(question, fakeAnswer);

char* scanSentence();

char* fscanfSentence(FILE*);

question searchQuestion(int);

fakeAnswer searchFakeAnswer(int);

void removeQuestion(question);

void printQuestion(question);

void printQuestionList(question*,int);

#endif