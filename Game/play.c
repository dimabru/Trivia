#include "play.h"
#define MAX_SIZE 80

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

question sortQ(int *indexFake)
{
	int size,i;
	static int level = 1;
	static int index = -1;
	question *list = getQuestions(&size);
	question error;
	error.level = -1;
	while (level < 11)
	{
		for (i = 0; i < size; i++)
		{
			if (list[i].level == level && i>index)
			{
				index = i;
				*indexFake = i;
				return list[i];
			}
		}
		index = -1;
		level++;
	}
	level = 1;
	return error;
}

int show_question()
{
	int size = 0, indexFake = 0,i;
	question show = sortQ(&indexFake);
	fakeAnswer *fake = getFakeAnswers(&size);
	fakeAnswer current;
	char getAnswer[MAX_SIZE];
	int random = 0;
	//for the for loop to know if we use correct answer;
	int flagCorrect = 0;
	int flagFake = 0;
	int save_correct_answer = 0;

	printf("%s\n", show.str);

	current = fake[indexFake];

	int c = current.fakeAmount;

	random = rand();
	random = random % current.fakeAmount;

	for (i = 0; i < current.fakeAmount + 1; i++)
	{
		if (i < current.fakeAmount)
		{
			printf("%d) %s\n", i, current.fakeList[i]);
			flagFake = 1;
		}
		if (i == random && flagCorrect == 0 && flagFake == 0)
		{
			printf("%d) %s\n", i, show.answer);
			flagCorrect = 1;
			save_correct_answer = i;
		}
		flagFake = 0;
	}

	fflush(stdin);
	scanf("%s", getAnswer);

	if (getAnswer == i)
	{
		return show.level;
	}
	return 0;
}

