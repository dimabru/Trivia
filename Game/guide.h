#define _CRT_SECURE_NO_WARNINGS
#ifndef _guide
#define _guide
#include "general.h"

#define MAX_SIZE 80
#define ALLOW 1
void guid_menu()
{
	//this value check if the guid loged in as he needed;
	int currect_password = 0; 
	int i = 0;
	char get_chose[MAX_SIZE];

	system("cls");
	while (get_chose[0] != 'q')
	{
		printf("a) to sign in\n");
		printf("b) to register\n");
		printf("c) to see student score list\n");
		printf("d) to see students details\n");
		printf("e) to see average score of the students\n");
		printf("f) to send massege to students\n");
		printf("q) previous screen\n");

		fflush(stdin);
		scanf("%s", get_chose);

		//im checking here if the user enters just one letter;
		if (get_chose[1] == '\0')
		{
			switch (get_chose[0])
			{
			case 'a':
				//if the password incurrect;
				if (!(enter_with_password()))
				{
					fflush(stdin);
					printf("incorrect password enter any key to continue\n");
					getch();
					get_chose[0] = 'e';
					get_chose[1] = '\0';
					system("cls");
				}
				else
				{
					currect_password = ALLOW;
				}
				break;
			case 'b':
				guid_menu();
				break;
			case 'c':
				//if the guid loged in as he needed;;
				if (!(currect_password))
				{
					fflush(stdin);
					printf("please log in first\n");
				}
				else
				{
					//////////////////////////////////////////////////////////////////////
					//here we need to show student from struct;
				}
				break;
				//to see students details
			case 'd':
				//if the guid loged in as he needed;;
				if (!(currect_password))
				{
					fflush(stdin);
					printf("please log in first\n");
				}
				else
				{
					//////////////////////////////////////////////////////////////////////
					//here we need to show student details from struct;
				}
				break;
				//to see average score of the students
			case 'e':
				//if the guid loged in as he needed;
				if (!(currect_password))
				{
					fflush(stdin);
					printf("please log in first\n");
				}
				else
				{
					//////////////////////////////////////////////////////////////////////
					//here we need to show student average from struct;
				}
				break;
				//to send massege to students;
			case 'f':
				//if the guid loged in as he needed;;
				if (!(currect_password))
				{
					fflush(stdin);
					printf("please log in first\n");
				}
				else
				{
					//////////////////////////////////////////////////////////////////////
					//here we need to show students from struct;
					//then let the guid chose one;
					//if exist more then one show relevent student;
					//lot of work here.................;
				}
				break;
			default:
				printf("you enterd illegal letter");
				break;
			}
		}
		//if the user enterd illegal sentence i cleare the arry;
		else
		{
			for (i = 0; i < MAX_SIZE;i++)
			{
				get_chose[i] = '\0';
			}
		}
		//clean screen.;
		system("cls");
	}
}


int enter_with_password()
{
	char get_pass[MAX_SIZE];
	printf("please enter your password\n");
	scanf("%s", get_pass);
	
	//here we need to check if the password is ture;

	return 0;
}

void guidRegister()
{
	unsigned long id = 0;
	printf("please enter your id\n");
	fflush(stdin);
	scanf("%d", id);
	//here we need to enter the id to data base;

	char user_name[MAX_SIZE];
	printf("please enter your name\n");
	fflush(stdin);
	scanf("%s", user_name);
	//here we need to enter the name to data base;

	char user_last_name[MAX_SIZE];
	printf("please enter your last name\n");
	fflush(stdin);
	scanf("%s", user_last_name);
	//here we need to enter the last name to data base;

	char get_pass[MAX_SIZE];
	printf("please enter your password\n");
	scanf("%s", get_pass);
	//here we need to enter the password to data base;

	//user type is guid;
	
	//games played = 0;

	//averege = 0;

	//highScore = 0;

	//scoreList;
}



#endif _guide