#define _CRT_SECURE_NO_WARNINGS
#ifndef _time_calculate
#define _time_calculate
#include <time.h>


time_t rawtime;
//define the 
struct tm *info;
int time_start = 0;
int time_end   = 0;

void time_now()
{
	printf("the time now is : %s \n", asctime(info));
}

void start_time()
{
	//dont toch it some it can solve a problem in the Futures;
	//char buffer[80];
	
	time(&rawtime);

	info = localtime(&rawtime);
	
	time_start = (info->tm_hour)*(60 * 60) + info->tm_min*60 + info->tm_sec;
}

void start_end()
{
	time(&rawtime);

	info = localtime(&rawtime);

	time_end = (info->tm_hour)*(60 * 60) + info->tm_min * 60 + info->tm_sec;
}

int sum_the_time()
{
	return  time_end - time_start;
}

#endif _time_calculate