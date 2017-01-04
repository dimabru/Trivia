#define _CRT_SECURE_NO_WARNINGS
#ifndef _files
#define _files
#include "general.h"

void setUsers(user *list,int size)
{
	int i,j;
	char path[16] = "data/users.txt";
	FILE *fp = fopen(path, "w");
	fprintf(fp,"%d\n", size);
	for (i = 0; i < size; i++)
	{
		fprintf(fp, "%s\n", list[i].firstName);
		fprintf(fp, "%s\n", list[i].lastName);
		fprintf(fp, "%s\n", list[i].ID);
		fprintf(fp, "%s\n", list[i].password);
		fprintf(fp, "%d\n", list[i].userType);
		fprintf(fp, "%d\n", list[i].gamesPlayed);
		fprintf(fp, "%d\n", list[i].average);
		fprintf(fp, "%d\n", list[i].highScore);
		for (j = 0; j < list[i].gamesPlayed; j++) fprintf(fp, "%d\n", list[i].scoreList[j]);
		fprintf(fp, "$\n");
	}
	fclose(fp);
	return;
}

void setQuestions(question *list, int size)
{
	int i;
	char path[19] = "data/questions.txt";
	FILE *fp = fopen(path, "w");
	fprintf(fp, "%d\n", size);
	for (i = 0; i < size; i++)
	{
		fprintf(fp, "%s\n", list[i].str);
		fprintf(fp, "%s\n", list[i].answer);
		fprintf(fp, "%d\n", list[i].ID);
		fprintf(fp, "%d\n", list[i].level);
		fprintf(fp, "%d\n", list[i].answered);
		fprintf(fp, "$\n");
	}
	fclose(fp);
	return;
}

void setFakeAnswers(fakeAnswer *list,int size)
{
	int i,j;
	char path[21] = "data/fakeAnswers.txt";
	FILE *fp = fopen(path, "w");
	fprintf(fp, "%d\n", size);
	for (i = 0; i < size; i++)
	{
		fprintf(fp, "%d\n", list[i].ID);
		fprintf(fp, "%d\n", list[i].fakeAmount);
		for (j = 0; j < list[i].fakeAmount; j++) fprintf(fp, "%s\n", list[i].fakeList[j]);
		fprintf(fp, "$\n");
	}
	fclose(fp);
	return;
}

void setMessages(message *list, int size)
{
	int i;
	char path[18] = "data/messages.txt";
	FILE *fp = fopen(path, "w");
	fprintf(fp, "%d\n", size);
	for (i = 0; i < size; i++)
	{
		fprintf(fp, "%s\n", list[i].ID);
		fprintf(fp, "%s\n", list[i].msg);
		fprintf(fp, "$\n");
	}
	fclose(fp);
	return;
}

void setBest(best *list, int size)
{
	int i;
	char path[20] = "data/bestResult.txt";
	FILE *fp = fopen(path, "w");
	fprintf(fp, "%d\n", size);
	for (i = 0; i < size; i++)
	{
		fprintf(fp, "%d\n", list[i].bestResult);
		fprintf(fp, "%s\n", list[i].ID);
		fprintf(fp, "$\n");
	}
	fclose(fp);
	return;
}

void setInstructions(char *msg)
{
	char path[22] = "data/instructions.txt";
	FILE *fp = fopen(path, "w");
	fprintf(fp, "%s\n", msg);
	fclose(fp);
	return;
}

void setCommentsForDev(char *msg)
{
	char path[26] = "data/comments_for_dev.txt";
	FILE *fp = fopen(path, "a");
	fprintf(fp, "%s\n", msg);
	fclose(fp);
	return;
}

#endif _files