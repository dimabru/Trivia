#define _CRT_SECURE_NO_WARNINGS
#ifndef _menus
#define _menus
#include "general.h"
#include "guide.h"

#define MAX_SIZE 80

void first_menu()
{
	int i = 0;
	char get_chose[MAX_SIZE];
	
	while (get_chose[0] != 'e')
	{
		printf("hellow\n");
		printf("a) for editor\n");
		printf("b) for guide\n");
		printf("c) for student\n");
		printf("e) for exit\n");

		fflush(stdin);
		scanf("%s", get_chose);

		//im checking here if the user enters just one letter;
		if (get_chose[1] == '\0')
		{
			switch (get_chose[0])
			{
			case 'a':
				break;
			case 'b':
				guid_menu();
				break;
			case 'c':
				break;
			default:
				printf("you enterd illegal letter");
				break;
			}
		}
		//if the user enterd illegal sentence i cleare the arry;
		else
		{
			for (i = 0; i < MAX_SIZE; i++)
			{
				get_chose[i] = '\0';
			}
		}
		//clean screen;
		system("cls");
	}
}


#endif _menus