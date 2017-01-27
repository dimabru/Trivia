#include "student.h"
/*This function print the menu for a student and calls functions according the option the student enterd*/
void student_menu(user stud)
{
	char temp[80], con;
	int selection = 1, BestRes;
	while ((selection != 4) && (selection != 3))
	{
		system("cls");
		printf("***********Student: %s %s***************\n", stud.firstName, stud.lastName);
		printf("Select one of the following options\n");
		printf("1) Play game\n");
		printf("2) View current record\n");
		printf("3) Receive Message\n");
		printf("4) Log off\n");
		printf("5) Quit\n");
		do{
			scanf("%s", temp);
			selection = whileNotInt(temp);
			if (selection < 1 || selection>5) printf("Wrong input. Try again\n");
		} while (selection < 1 || selection>5);
		switch (selection)
		{
		case 1:
			student_menu_play_game(stud);
			break;
		case 2:
			BestRes = view_current_record(&stud.ID);
			if (BestRes == -1)
			{
				system("cls");
				printf("There is no record\n You have not played yet\nPress any key to continue");
				_getch();
			}
			else
			{
				system("cls");
				printf("Your record: %d\nTry to get a greater record with a new game! :)\nPress any key to continue\n", BestRes);
				_getch();
			}
			break;
		case 3:
			menu_receivemsg(stud.ID);
			break;
		case 4:
			return;
		case 5:
			printf("Have a nice day\n");
			exit(0);
		}
	}
}

void student_menu_play_game(user stud)
{
	int scoore = start_to_play(stud);
}

/*This function returns the record of the user received.
If it isn't exist- returns -1 check of the unit testingggggg*/
int view_current_record(char* id_user)
{
	int size, i;
	best *list;
	list = getBest(&size);

	for (i = 0; i < size; i++)
	{
		if (!strcmp(list[i].ID, id_user)) return list[i].bestResult;
	}
	if (size) free(list);
	return -1;
}
/*This function represent the message the guide had write to the student with the id received*/
void menu_receivemsg(char* id)
{
	int size,i;
	message *list = getMessages(&size);
	for (i = 0; i < size; i++)
	{
		if (!strcmp(list[i].ID, id)) break;
	}
	system("cls");
	if (i == size) printf("No message to display\n");
	else
	{
		puts("Message from guide team:\n");
		printf("%s\n", list[i].msg);
	}
	printf("Press any key to continue\n");
	_getch();
	if (size) free(list);
	return;
}