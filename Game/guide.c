#include "guide.h"

void guide_menu(user gid)
{
	char temp[80];
	int selection;
	while (1)
	{
		system("cls");
		printf("***********Guide: %s %s***************\n", gid.firstName, gid.lastName);
		printf("Select one of the following options\n");
		printf("1) Play game\n");
		printf("2) Edit game instructions\n");
		printf("3) View student score\n");
		printf("4) View user data\n");
		printf("5) View questions data\n");
		printf("6) View general average\n");
		printf("7) Send message to student\n");
		printf("8) Send message to R&D team\n");
		printf("9) Log off\n");
		printf("10) Quit\n");
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
			menu_instructions();
			break;
		case 3:
			menu_studentScore(); //located in editor.h
			break;
		case 4:
			menu_userData(); //located in editor.h
			break;
		case 5:
			menu_viewQuestions();
			break;
		case 6:
			menu_average(); //located in editor.h
			break;
		case 7:
			menu_sendMessage();
			break;
		case 8:
			menu_RD();
		case 9:
			return;
		case 10:
			printf("Have a nice day\n");
			exit(0);
		}
	}
}

void menu_instructions()
{
	char msg[1000],ch[80];
	system("cls");
	printf("***********Set instructions***************\n");
	strcpy(msg, getInstructions());
	printf("The instructions are for all students to see when entering program\n");
	if (!strcmp(msg, "None")) printf("There are no instructions at the moment\n");
	else
	{
		printf("Current instructions:\n");
		printf("%s\n", msg);
	}
	fflush(stdin);
	printf("1) Edit instructions\n");
	printf("2) Reset instructions\n");
	printf("Anything else to return to menu\n");
	scanf("%s", &ch);
	if (ch[0] == '1' && ch[1]=='\0')
	{
		printf("Enter new message to display:\n");
		strcpy(msg, scanSentence());
		if (rUsure())
		{
			setInstructions(msg);
			printf("Instructions succesfully changed\n");
		}
	}
	else if (ch[0] == '2' && ch[1] == '\0')
	{
		setInstructions("None");
		printf("Reset succesfull\n");
	}
	printf("Press any key to continue\n");
	_getch();
}

void menu_viewQuestions()
{
	int size,i,j;
	question *q = getQuestions(&size);
	fakeAnswer *fa = getFakeAnswers(&size);
	system("cls");
	printf("***********View Questions***************\n");
	if (!size) printf("No questions to present\n");
	else
	{
		printf("List of questions:\n************\n");
		for (i = 0; i < size; i++)
		{
			printQuestion(q[i]);
			printf("Fake answers:\n");
			for (j = 0; j < fa[i].fakeAmount; j++) printf("%s\n", fa[i].fakeList[j]);
			printf("*******************\n");
		}
	}
	printf("Press any key to continue\n");
	_getch();
	return;
}

void menu_sendMessage()
{
	char ch[80],fname[80],lname[80],msg[1000],id[80];
	int size,i,cnt=0;
	user *list = getUsers(&size),found;
	message m;
	fflush(stdin);
	system("cls");
	printf("***********Send Message***************\n");
	printf("Select one of the following options\n");
	printf("1) Search student by name\n");
	printf("2) Search student by ID\n");
	printf("Enter anything else to return to menu\n");
	scanf("%s", ch);
	if (ch[0] == '1' && ch[1] == '\0')
	{
		printf("Enter first name: ");
		scanf("%s", fname);
		printf("Enter last name: ");
		scanf("%s", lname);
		for (i = 0; i < size; i++)
		{
			if (!strcmp(list[i].firstName, fname) && !strcmp(list[i].lastName, lname) && list[i].userType==student)
			{
				found = list[i];
				cnt++;
			}
		}
		if (!cnt)
		{
			printf("No such student\n");
			printf("Press any key to continue\n");
			_getch();
			return;
		}
		else if (cnt == 1)
		{
			printf("Enter message for %s %s\n", fname, lname);
			strcpy(msg, scanSentence());
		}
		else
		{
			printf("Found several users with same name. Enter ID\n");
			scanf("%s", id);
			found = searchUser(id);
			if (found.average != -1 && found.userType == student)
			{
				printf("Enter message for %s %s\n", found.firstName, found.lastName);
				strcpy(msg, scanSentence());
			}
			else
			{
				printf("Failed to find ID\n");
				printf("Press any key to continue\n");
				_getch();
				return;
			}
		}
		strcpy(m.msg, msg);
		strcpy(m.ID, found.ID);
		addMessage(m);
	}
	if (ch[0] == '2' && ch[1] == '\0')
	{
		printf("Enter ID\n");
		scanf("%s", id);
		found = searchUser(id);
		if (found.average != -1 && found.userType == student)
		{
			printf("Enter message for %s %s\n", found.firstName, found.lastName);
			strcpy(msg, scanSentence());
		}
		else printf("Failed to find ID\n");
		strcpy(m.msg, msg);
		strcpy(m.ID, found.ID);
		addMessage(m);
	}
	printf("Press any key to continue\n");
	_getch();
	return;
}

void menu_RD()
{
	char msg[1000];
	printf("***********Message to R&D***************\n");
	printf("Enter message for reasearch and development team\n");
	strcpy(msg,scanSentence());
	setCommentsForDev(msg);
	printf("Message sent\n");
	printf("Press any key to continue\n");
	_getch();
	return;
}