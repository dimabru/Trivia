#include "play.h"
#define MAX_SIZE 80
#define beggining_of 10
#define difference 10

//for color;
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define RESET   "\x1b[0m"


/*This function controls the game
It calls the function show_question and calculates the score according the answers and the time left
It returns the final score*/
int start_to_play(type uType)
{
	//for the for loop;
	int i = 0;
	int sum = 0;
	int score = 0;
	int save_correct_answer = 0;
	int temp = 0, secLeft = 0, houre = 0;
	

	char UT[80];
	if (uType == student) strcpy(UT, "Student");
	else if (uType == editor) strcpy(UT, "Editor");
	else strcpy(UT, "Guide");
	system("cls");
	fflush(stdin);
	printf("*********%s Log in***********\n", UT);

	start_time();
	for (i = 0; i < NUM_OF_QUESTION; i++)
	{
		printf("question number %d\n", i);
		sum += show_question();
		if (sum != 0)
		{
			save_correct_answer += sum / sum;
		}
		system("cls");
		fflush(stdin);
		printf("*********%s Log in***********\n", UT);
	}
	start_end();

	printf(YELLOW    "************************************************"    RESET "\n");
	printf(GREEN   "************************************************"      RESET "\n");
	printf(GREEN "you answerd %d correct answer\n" RESET, save_correct_answer);

	///to show the user how long time its took him
	houre = sum_the_time() / 3600;
	temp = sum_the_time();
	printf(GREEN "its took you %d hour" RESET, houre);
	secLeft = temp - houre * 3600;
	//min
	temp = secLeft / 60;
	printf(GREEN " %d minute"RESET, temp);

	temp = secLeft - temp * 60;
	printf(GREEN" %d second\n"RESET, temp);
	
	temp = sum_the_time();
	score = NUM_OF_QUESTION + ((10 * NUM_OF_QUESTION * NUM_OF_QUESTION) / temp) + sum;
	printf(GREEN"your scoore is %d\n"RESET, score);
	printf(GREEN   "************************************************"RESET "\n");
	printf(YELLOW  "************************************************"RESET "\n");
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
	question error,found;
	error.level = -1;
	while (level < 11)
	{
		for (i = 0; i < size; i++)
		{
			if (list[i].level == level && i>index)
			{
				index = i;
				*indexFake = i;
				found = list[i];
				free(list);
				return found;
			}
		}
		index = -1;
		level++;
	}
	level = 1;
	return error;
}
/*This function represent a question and the answers the user need to choose between them.
the function receive a answer from the user
if he will enter the correct answer- the function will return 1,if not- will return 0*/
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
	random = random % current.fakeAmount + 1;
	
	for (i = 0; i < current.fakeAmount+1 ; i++)
	{
		
		if (i < current.fakeAmount && i != random)
		{
			printf("%d) %s\n", i, current.fakeList[i]);
			flagFake = 1;
		}
		if (i == random && flagCorrect == 0 && flagFake == 0)
		{
			printf("%d) %s\n", i, show.answer);
			flagCorrect = 1;
			save_correct_answer = i;
			i--;
		}
		flagFake = 0;
	}

	fflush(stdin);
	i = whileNotInt(getAnswer);

	if (i == save_correct_answer)
	{
		return show.level;
	}
	if (size) free(fake);
	return 0;
}

