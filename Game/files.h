#define _CRT_SECURE_NO_WARNINGS
#ifndef _files
#define _files
#include "general.h"

void setUsers(user*, int);

user* getUsers(int*);

void resetUsers();

void setQuestions(question*, int);

question* getQuestions(int*);

void resetQuestions();

void setFakeAnswers(fakeAnswer*, int);

fakeAnswer* getFakeAnswers(int*);

void setMessages(message*, int);

message* getMessages(int*);

void setBest(best*, int);

best* getBest(int*);

void setInstructions(char *msg);

char* getInstructions();

void setCommentsForDev(char *msg);

void resetAll();

#endif _files