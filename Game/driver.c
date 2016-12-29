#include "general.h"
#include "time_calculate.h"
//#include "vld.h"

int main()
{
	int num;

	start_time();
	printf("enter eny key to calculate the time\n\n");
	getch();
	start_end();
	printf("its took you %d secunds\n", sum_the_time());
	getch();
	return 0;
}

