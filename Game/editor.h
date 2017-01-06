#define _CRT_SECURE_NO_WARNINGS
#ifndef _editor
#define _editor

#include "general.h"

void editor_menu(user edit)
{
	system("cls");
	char temp[80];
	int selection;
	printf("Select one of the following options\n");
	printf("1) Play game\n");
	printf("2) Add a question\n");
	printf("3) Add fake answers\n");
	printf("4) Delete a question\n");
	printf("5) View student score\n");
	printf("6) View user data\n");
	printf("7) View general average\n");
	printf("8) Change a question\n");
	printf("9) Back\n");
	printf("10) Log off\n");
	printf("11) Quit\n");
	do{
		scanf("%s", temp);
		selection = whileNotInt(temp);
		if (selection < 1 || selection>11) printf("Wrong input. Try again\n");
	} while (selection < 1 || selection>11);

}

#endif