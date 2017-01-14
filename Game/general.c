#include "general.h"
#include "files.h"

long inputCheck(char* str)
{
	int i;
	long num = 0;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] >= '0'&&str[i] <= '9') num = num * 10 + str[i] - 48;
		else return -1;
	}
	if (strlen(str) > 10) return -1;
	return num;
}

long whileNotInt(char* str)
{
	long num = inputCheck(str);
	char *arr = (char*)malloc(sizeof(1));
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
		fflush(stdin);
		printf("Are you sure? (enter y if yes, n if no)\n");
		scanf("%c", &x);
		if (x == 'y' || x == 'Y') return 1;
		if (x == 'n' || x == 'N') return 0;
		printf("Wrong input. Try again\n");
	}
}

void printUser(user unit)
{
	char x[80];
	int i;
	if (unit.userType == 0) strcpy(x,"student");
	else if (unit.userType == 1) strcpy(x, "editor");
	else strcpy(x, "guide");
	printf("first name: %s\n", unit.firstName);
	printf("last name: %s\n", unit.lastName);
	printf("ID: %s\n", unit.ID);
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

void printStudent(user unit)
{
	int i;
	printf("first name: %s\n", unit.firstName);
	printf("last name: %s\n", unit.lastName);
	printf("ID: %s\n", unit.ID);
	printf("games played: %d\n", unit.gamesPlayed);
	printf("average: %d\n", unit.average);
	printf("high score: %d\n", unit.highScore);
	if (unit.gamesPlayed)
	{
		printf("Score List:\n");
		for (i = 0; i < unit.gamesPlayed; i++) printf("%d) %d\n", i + 1, unit.scoreList[i]);
	}
	return;
}

void printUserList(user* list, int size)
{
	int i;
	system("cls");
	printf("List of users:\n");
	for (i = 0; i < size; i++)
	{
		printUser(list[i]);
		printf("*******************************\n");
	}
}

void printStudentList(user *list, int size)
{
	int i,cnt=0;
	system("cls");
	printf("List of users:\n");
	for (i = 0; i < size; i++)
	{
		if (list[i].userType == student)
		{
			cnt++;
			printUser(list[i]);
			printf("*******************************\n");
		}
	}
	if (!cnt) printf("No students in database\n");
	return;
}

void printQuestion(question q)
{
	printf("ID: %d\n\n", q.ID);
	printf("Level: %d\n", q.level);
	printf("%s\n", q.str);
	printf("Correct Answer: %s\n", q.answer);
	return;
}

void printQuestionList(question* list, int size)
{
	int i;
	if (list == NULL)
	{
		printf("No questions to display\n");
		return;
	}
	printf("List of questions:\n************\n");
	for (i = 0; i < size; i++)
	{
		printQuestion(list[i]);
		printf("************\n");
	}
	return;
}

user searchUser(char *id)
{
	int i, size = 0;
	user error, *list = getUsers(&size);
	error.average = -1;
	for (i = 0; i < size; i++)
	{
		if (!strcmp(list[i].ID, id)) return list[i];
	}
	return error;
}

void addUser(user newUser)
{
	int size=0,i;
	user *list = getUsers(&size),*newList;
	char fname[80];
	if (size)
	{
		newList = (user*)malloc(sizeof(user)*(size + 1));
		for (i = 0; i < size; i++) newList[i] = list[i];
	}
	else newList = (user*)malloc(sizeof(user));
	newList[size] = newUser;
	setUsers(newList, size + 1);
	printf("User added succesfully\n");
	return;
}

void addQuestion(question q, fakeAnswer fa)
{
	int size = 0,i;
	question *qList = getQuestions(&size),*newQ;
	fakeAnswer *faList = getFakeAnswers(&size),*newFA;
	if (size)
	{
		q.ID = qList[size - 1].ID + 1;
		fa.ID = faList[size - 1].ID + 1;
	}
	else
	{
		q.ID = 0;
		fa.ID = 0;
	}
	if (size)
	{
		newQ = (question*)malloc(sizeof(question)*(size + 1));
		for (i = 0; i < size; i++) newQ[i] = qList[i];
		newFA = (fakeAnswer*)malloc(sizeof(fakeAnswer)*(size + 1));
		for (i = 0; i < size; i++) newFA[i] = faList[i];
	}
	else
	{
		newQ = (question*)malloc(sizeof(question));
		newFA = (fakeAnswer*)malloc(sizeof(fakeAnswer));
	}
	newQ[size] = q;
	newFA[size] = fa;
	setQuestions(newQ, size + 1);
	setFakeAnswers(newFA, size + 1);
	printf("Question added succesfully\n");
	return;
}

char* scanSentence()
{
	char ch, str[1000];
	int i = 0;
	fflush(stdin);
	while (ch = getchar())
	{
		if (ch == '\n' || ch == '\0') break;
		else str[i++] = ch;
	}
	str[i] = '\0';
	return str;
}

char* fscanfSentence(FILE *fp)
{
	char ch, str[1000];
	int i = 0, first=1;
	fflush(stdin);
	while (fscanf(fp,"%c",&ch))
	{
		if (first && ch == '\n') fscanf(fp, "%c", &ch);
		first = 0;
		if (ch == '\n' || ch == '\0') break;
		else str[i++] = ch;
	}
	str[i] = '\0';
	return str;
}

question searchQuestion(int id)
{
	int size,i;
	question *list = getQuestions(&size);
	question error;
	error.ID = -1;
	for (i = 0; i < size; i++)
	{
		if (list[i].ID == id) return list[i];
	}
	return error;
}

fakeAnswer searchFakeAnswer(int id)
{
	int size,i;
	fakeAnswer *list = getFakeAnswers(&size);
	for (i = 0; i < size; i++) if (list[i].ID == id) return list[i];
}

void removeQuestion(question q)
{
	int size,i,j=0;
	question *list = getQuestions(&size), *newList = (question*)malloc(sizeof(question)*(size-1));
	fakeAnswer fa = searchFakeAnswer(q.ID),*newFA = (fakeAnswer*)malloc(sizeof(fakeAnswer)*(size-1));
	fakeAnswer *faList = getFakeAnswers(&size);
	for (i = 0; i < size; i++)
	{
		if (list[i].ID != q.ID)
		{
			newList[j] = list[i];
			newFA[j++] = faList[i];
		}
	}
	if (size > 1)
	{
		setQuestions(newList, size - 1);
		setFakeAnswers(newFA, size - 1);
	}
	else resetQuestions();
	return;
}

int getAverage()
{
	int size = 0,i;
	user *list = getUsers(&size);
	float amount = 0,sum=0;
	for (i = 0; i < size; i++)
	{
		if (list[i].userType == student)
		{
			amount++;
			sum += list[i].average;
		}
	}
	if (!amount) return 0;
	return sum / amount;
}

void resetScores()
{
	int size = 0, i,j;
	setBest(NULL, 0);
	user *list = getUsers(&size);
	for (i = 0; i < size; i++)
	{
		list[i].average = 0;
		free(list[i].scoreList);
		list[i].gamesPlayed = 0;
		list[i].highScore = 0;
	}
	return;
}

void changeQuestion(question q)
{
	int i,amount;
	question nq;
	char temp[80];
	long level;
	fakeAnswer fa,f=searchFakeAnswer(q.ID);
	system("cls");
	printf("Current question information:\n");
	printQuestion(q);
	printf("Fake answers:\n");
	for (i = 0; i < f.fakeAmount; i++) printf("%s\n", f.fakeList[i]);
	printf("************************\n");
	printf("Enter the changed question:\n");
	strcpy(nq.str, scanSentence());
	printf("Select level of question from 1 to 10 (1 is the easiest, 10 is the hardest)\n");
	do{
		fflush(stdin);
		scanf("%s", temp);
		level = whileNotInt(temp);
		if (level < 1 || level>10) printf("Wrong input. Try again\n");
	} while (level < 1 || level>10);
	nq.level = level;
	printf("Enter correct answer: ");
	strcpy(nq.answer, scanSentence());
	printf("How many fake answers do you wish to give? (no more than 5)\n");
	do{
		scanf("%s", temp);
		amount = whileNotInt(temp);
		if (amount < 1 || amount > 5) printf("Wrong input. Try again\n");
	} while (amount < 1 || amount > 5);
	fa.fakeAmount = amount;
	for (i = 0; i < amount; i++)
	{
		printf("Enter fake answer number %d: ", i + 1);
		do{
			strcpy(fa.fakeList[i], scanSentence());
			if (!strcmp(q.answer, fa.fakeList[i])) printf("That is the correct answer. Try again\n");
		} while (!strcmp(q.answer, fa.fakeList[i]));
	}
	fa.ID = q.ID;
	nq.ID = q.ID;
	nq.answered = 0;
	removeQuestion(q);
	addQuestion(nq, fa);
	return;
}

void addMessage(message m)
{
	int i, size = 0,j;
	message *list = getMessages(&size);
	message *nlist;
	for (i = 0; i < size; i++) if (!strcmp(m.ID, list[i].ID)) break;
	if (i == size)
	{
		nlist = (message*)malloc(sizeof(message)*(size + 1));
		for (j = 0; j < size; j++) nlist[j] = list[j];
		nlist[size] = m;
		free(list);
		setMessages(nlist, size + 1);
		free(nlist);
	}
	else
	{
		strcpy(list[i].msg, m.msg);
		setMessages(list, size);
		free(list);
	}
	printf("Message added succesfully\n");
	return;
}