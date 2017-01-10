#include "editor.h"

void editor_menu(user edit)
{
	char temp[80];
	int selection;
	while (1)
	{
		system("cls");
		printf("***********Editor: %s %s***************\n", edit.firstName, edit.lastName);
		printf("Select one of the following options\n");
		printf("1) Play game\n");
		printf("2) Add a question\n");
		printf("3) Delete a question\n");
		printf("4) View student score\n");
		printf("5) View user data\n");
		printf("6) View general average\n");
		printf("7) Change a question\n");
		printf("8) Log off\n");
		printf("9) Quit\n");
		do{
			scanf("%s", temp);
			selection = whileNotInt(temp);
			if (selection < 1 || selection>10) printf("Wrong input. Try again\n");
		} while (selection < 1 || selection>10);
		switch (selection)
		{
		case 1:
			break;
		case 2:
			menu_addQuestion();
			break;
		case 3:
			menu_deleteQuestion();
			break;
		}
	}
}

void menu_addQuestion()
{
	question q;
	fakeAnswer fa;
	char temp[80],ch,str[1000];
	int level, amount, i = 0;
	system("cls");
	printf("*****************Add Question*******************\n");
	printf("Select level of question from 1 to 10 (1 is the easiest, 10 is the hardest)\n");
	do{
		fflush(stdin);
		scanf("%s", temp);
		level = whileNotInt(temp);
		if (level < 1 || level>10) printf("Wrong input. Try again\n");
	} while (level < 1 || level>10);
	q.level = level;
	q.answered = 0;
	while (1)
	{
		printf("Write the question:\n");
		strcpy(q.str, scanSentence());
		if (rUsure()) break;
	}
	printf("Enter correct answer: ");
	strcpy(q.answer, scanSentence());
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
			strcpy(fa.fakeList[i],scanSentence());
			if (!strcmp(q.answer, fa.fakeList[i])) printf("That is the correct answer. Try again\n");
		} while (!strcmp(q.answer, fa.fakeList[i]));
	}
	addQuestion(q, fa);
	_getch();
	return;
}

void menu_deleteQuestion()
{
	question remove;
	char temp[80];
	long selection,id;
	system("cls");
	printf("*****************Delete Question*******************\n");
	printf("Select one of the following options\n");
	printf("1) Search a question using ID\n");
	printf("2) Select a question from list\n");
	do{
		fflush(stdin);
		scanf("%s", temp);
		selection = whileNotInt(temp);
		if (selection < 1 || selection>2) printf("Wrong input. Try again\n");
	} while (selection < 1 || selection>2);
	switch (selection)
	{
	case 1:
		printf("Enter ID of a question to search\n");
		fflush(stdin);
		scanf("%s", temp);
		id = whileNotInt(temp);
		remove = searchQuestion(id);
		if (remove.ID == -1) printf("Question doesn't exist\n");
		else removeQuestion(remove);
		_getch();
		break;
	}
}