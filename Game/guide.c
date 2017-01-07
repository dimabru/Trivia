#include "guide.h"

int correct_password = 0;

void guide_menu()
{
	//this value checke if the guide logged in as he needed;

	int i = 0;
	int get_choose = 1000;

	system("cls");
	while (get_choose != 0)
	{
		printf("1) Sign in\n");
		printf("2) Register\n");
		printf("3) to see student score list\n");
		printf("4) to see students details\n");
		printf("5) to see average score of the students\n");
		printf("6) to send massage to students\n");
		printf("7) to send massage to developers\n");
		printf("8) to write instruction in the first screen\n");
		printf("9) to view all question or just one question\n");
		printf("10)to play game\n");
		//delete this shit as soon as you can;
		printf("11) play game\n");
		printf("0) previous screen\n");

		fflush(stdin);
		scanf("%d", &get_choose);

		//im checking here if the user enters just one letter;
		if (get_choose <= 11)
		{
			switch (get_choose)
			{
			case 1:
				correct_password = sign_in();
				//get the user out if he is wrong;
				if (!(correct_password))
					get_choose = correct_password;
				break;
			case 2:
				guideRegister();
				break;
				//to see student score list;
			case 3:
				student_score_list();
				break;
				//to see students details
			case 4:
				students_details();
				break;
				//to see average score of the students
			case 5:
				average_score();
				break;
				//to send massege to students;
			case 6:
				send_massage_to_students();
				break;
				//to send massege to developers
			case 7:
				massage_to_developers();
				break;
				//to write instruction in the first screen;
			case 8:
				write_instructions_in_the_first_screen();
				break;
			case 9:
				view_all_questions_or_one();
				break;
				//to play game;
			case 10:
				//in "play.h";
				start_to_play();
				break;
				//back door;
			case 11:
				correct_password = !correct_password;
				break;
			default:
				printf("you entered illegal letter");
				break;
			}
		}
		//if the user enterd illegal sentence i cleare the arry;
		else
		{
			get_choose = 1000;
			fflush(stdin);
		}
		//clean screen.;
		system("cls");
	}
}

int sign_in()
{
	//if the password incorrect;
	if (!(enter_with_password()))
	{
		fflush(stdin);
		printf("incorrect password enter any key to continue\n");
		getch();
		system("cls");
		return 0;
	}
	return 1;
}

void student_score_list()
{
	//if the guid loged in as he needed;;
	if (!(correct_password))
	{
		fflush(stdin);
		printf("please log in first\n");
		getch();
	}
	else
	{
		//////////////////////////////////////////////////////////////////////
		//here we need to show student from struct;
	}
	return;
}

void students_details()
{
	//if the guid loged in as he needed;
	if (!(correct_password))
	{
		fflush(stdin);
		printf("please log in first\n");
		getch();
	}
	else
	{
		//////////////////////////////////////////////////////////////////////
		//here we need to show student details from struct;
	}
}

void average_score()
{
	//if the guid loged in as he needed;
	if (!(correct_password))
	{
		fflush(stdin);
		printf("please log in first\n");
		getch();
	}
	else
	{
		//////////////////////////////////////////////////////////////////////
		//here we need to show student average from struct;
	}
}

void send_massage_to_students()
{
	//if the guid loged in as he needed;;
	if (!(correct_password))
	{
		fflush(stdin);
		printf("please log in first\n");
		getch();
	}
	else
	{
		//////////////////////////////////////////////////////////////////////
		//here we need to show students from struct;
		//then let the guid chose one;
		//if exist more then one show relevent student;
		//lot of work here.................;
	}
}

void massage_to_developers()
{
	//if the guid loged in as he needed;;
	if (!(correct_password))
	{
		fflush(stdin);
		printf("please log in first\n");
		getch();
	}
	else
	{
		//////////////////////////////////////////////////////////////////////
		char message_for_dev[MESSAGE_SIZE];
		printf("please enter your message\n");
		fflush(stdin);
		scanf("%s", message_for_dev);

		printf("the message recived\n");
		printf("enter any key to continu\n");
		getch();
	}
}

void write_instructions_in_the_first_screen()
{
	//if the guid loged in as he needed;;
	if (!(correct_password))
	{
		fflush(stdin);
		printf("please log in first\n");
		getch();
	}
	else
	{
		//////////////////////////////////////////////////////////////////////
		char instruction[MESSAGE_SIZE];
		printf("please enter your message\n");
		fflush(stdin);
		scanf("%s", instruction);

		printf("the instructions received\n");
		printf("enter any key to continue\n");
		getch();
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

void guideRegister()
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

void view_all_questions_or_one()
{
	//if the guide logged in as he needed;
	if (!(correct_password))
	{
		fflush(stdin);
		printf("please log in first\n");
		getch();
	}
	else
	{
		char *get_choose_2 = (char*)malloc(sizeof(MAX_SIZE));
		printf("1) to see all questions and choose one of them\n");
		printf("2) to choose one question\n");
		fflush(stdin);
		scanf("%s", get_choose_2);
		if (whileNotInt(get_choose_2) == 1)
		{
			//////////////////////////////////////////////////////////////////////
			//here we need to show the questions from the struct;
		}
		else if (whileNotInt(get_choose_2) == 2)
		{
			//////////////////////////////////////////////////////////////////////
			//here we need to show specific question from the struct;
		}
		else
		{
			printf("you enterd illegal value\n");
			printf("please enter any key to cuntinue\n");
			getch();
		}
		free(get_choose_2);
	}
}