#define _CRT_SECURE_NO_WARNINGS
#ifndef _files
#define _files

#include "general.h"

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

	printf("%d\n", time_start);


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

#endif _files