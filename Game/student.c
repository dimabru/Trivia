#include "student.h"

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
		printf("3) Log off\n");
		printf("4) Quit\n");
		do{
			scanf("%s", temp);
			selection = whileNotInt(temp);
			if (selection < 1 || selection>5) printf("Wrong input. Try again\n");
		} while (selection < 1 || selection>5);
		switch (selection)
		{
		case 1:
			system("cls");
			printf("playing the game\n");
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
			system("cls");
			first_menu();

			break;
		case 4:
			exit(1);
			break;
		}
	}
}

int view_current_record(char* id_user)
{
	int size, i;
	best *list;
	list = getBest(&size);

	for (i = 0; i < size; i++)
	{
		if (!strcmp(list[i].ID, id_user)) return list[i].bestResult;
	}
	return -1;
}


