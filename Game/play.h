#define _CRT_SECURE_NO_WARNINGS
#ifndef _play
#define _play
#include "general.h"
#include "time_calculate.h"

void start_to_play()
{
	start_time();
	printf("enter eny key to calculate the time\n\n");
	getch();
	start_end();
	printf("its took you %d secunds\n", sum_the_time());
}
#endif _play