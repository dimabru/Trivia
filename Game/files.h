#define _CRT_SECURE_NO_WARNINGS
#ifndef _files
#define _files


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
	free(list);
	return;
}

user* getUsers(int *size)
{
	int i, j, *scoreList;
	char path[16] = "data/users.txt",ch;
	FILE *fp = fopen(path, "r");
	if (!fp)
	{
		printf("Unable to open file\n");
		return NULL;
	}
	user *list;
	fscanf(fp,"%d", size);
	list = (user*)malloc(sizeof(user)*(*size));
	for (i = 0; i < *size; i++)
	{
		fscanf(fp, "%s", list[i].firstName);
		fscanf(fp, "%s", list[i].lastName);
		fscanf(fp, "%s", list[i].ID);
		fscanf(fp, "%s", list[i].password);
		fscanf(fp, "%d", &list[i].userType);
		fscanf(fp, "%d", &list[i].gamesPlayed);
		fscanf(fp, "%d", &list[i].average);
		fscanf(fp, "%d", &list[i].highScore);
		scoreList = (int*)malloc(sizeof(int)*list[i].gamesPlayed);
		list[i].scoreList = scoreList;
		for (j = 0; j < list[i].gamesPlayed; j++) fscanf(fp, "%d", &list[i].scoreList[j]);
		fscanf(fp,"%c",&ch);
	}
	fclose(fp);
	return list;
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

question* getQuestions(int *size)
{
	int i;
	char path[19] = "data/questions.txt",ch;
	FILE *fp = fopen(path, "r");
	question *list;
	fscanf(fp, "%d", size);
	list = (question*)malloc(sizeof(question)*(*size));
	for (i = 0; i < *size; i++)
	{
		fscanf(fp, "%s", list[i].str);
		fscanf(fp, "%s", list[i].answer);
		fscanf(fp, "%d", &list[i].ID);
		fscanf(fp, "%d", &list[i].level);
		fscanf(fp, "%d", &list[i].answered);
		fscanf(fp, "%c", &ch);
	}
	fclose(fp);
	return list;
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

fakeAnswer* getFakeAnswers(int *size)
{
	int i,j;
	char path[21] = "data/fakeAnswers.txt",ch;
	FILE *fp = fopen(path, "r");
	fakeAnswer *list;
	fscanf(fp, "%d", size);
	list = (fakeAnswer*)malloc(sizeof(fakeAnswer)*(*size));
	for (i = 0; i < *size; i++)
	{
		fscanf(fp, "%d", &list[i].ID);
		fscanf(fp, "%d", &list[i].fakeAmount);
		for (j = 0; j < list[i].fakeAmount; j++) fscanf(fp, "%s", list[i].fakeList[j]);
		fscanf(fp, "%c", &ch);
	}
	fclose(fp);
	return list;
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

message* getMessages(int *size)
{
	int i;
	char path[18] = "data/messages.txt",ch;
	FILE *fp = fopen(path, "r");
	message *list;
	fscanf(fp, "%d", size);
	list = (message*)malloc(sizeof(message)*(*size));
	for (i = 0; i < *size; i++)
	{
		fscanf(fp, "%s", list[i].ID);
		fscanf(fp, "%s", list[i].msg);
		fscanf(fp, "%c", &ch);
	}
	fclose(fp);
	return list;
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

best* getBest(int *size)
{
	int i;
	char path[20] = "data/bestResult.txt",ch;
	FILE *fp = fopen(path, "r");
	best *list;
	fscanf(fp, "%d", size);
	list = (best*)malloc(sizeof(best)*(*size));
	for (i = 0; i < *size; i++)
	{
		fscanf(fp, "%d", &list[i].bestResult);
		fscanf(fp, "%s", list[i].ID);
		fscanf(fp, "%c", &ch);
	}
	fclose(fp);
	return list;
}

void setInstructions(char *msg)
{
	char path[22] = "data/instructions.txt";
	FILE *fp = fopen(path, "w");
	fprintf(fp, "%s\n", msg);
	fclose(fp);
	return;
}

char* getInstructions()
{
	char path[22] = "data/instructions.txt",msg[6400];
	FILE *fp = fopen(path, "r");
	fscanf(fp, "%s", msg);
	fclose(fp);
	return msg;
}

void setCommentsForDev(char *msg)
{
	char path[26] = "data/comments_for_dev.txt";
	FILE *fp = fopen(path, "a");
	fprintf(fp, "%s\n", msg);
	fprintf(fp, "$\n");
	fclose(fp);
	return;
}

#endif _files