#define _CRT_SECURE_NO_WARNINGS
#ifndef _play
#define _play
#include "time_calculate.h"

#define NUM_OF_QUESTION 5

int show_question();

int start_to_play()
{
	//for the for loop;
	int i = 0;
	int sum = 0;
	int score = 0;
	int temp = 0, secLeft = 0, houre = 0;
	start_time();


	for (i = 0; i < NUM_OF_QUESTION; i++)
	{
		sum += show_question();
	}
	start_end();
	if (sum_the_time() < 3)
	{
		printf("your score is %d\n", sum + 30);
		score = sum + 30;
	}
	else if (sum_the_time() < 7)
	{
		printf("your score is %d\n", sum + 25);
		score = sum + 25;
	}
	else if (sum_the_time() < 10)
	{
		printf("your score is %d\n", sum + 20);
		score = sum + 20;
	}
	else if (sum_the_time() < 15)
	{
		printf("your score is %d\n", sum + 15);
		score = sum + 15;
	}
	else if (sum_the_time() < 17)
	{
		printf("your score is %d\n", sum + 10);
		score = sum + 10;
	}
	else if (sum_the_time() < 20)
	{
		printf("your score is %d\n", sum + 5);
		score = sum + 5;
	}
	else if (sum_the_time() > 20)
	{
		printf("your score is %d\n", sum);
		score = sum;
	}
	houre = sum_the_time() / 3600;
	temp = sum_the_time();
	printf("its took you %d hour", houre);
	secLeft = temp - houre * 3600;
	//min
	temp = secLeft / 60;
	printf(" %d minuet", temp);

	temp = secLeft - temp * 60;
	printf(" %d second\n", temp);
	printf("press any key to cuntinue\n");
	getch();

	//this function return the score so you can enter it to his achivement;
	return score;
}

int show_question()
{
	///////////////////////////////////////////////////////////////////////////
	printf("hi im a question please answer me\n");
	_getch();
	return 1;
}

#endif _play