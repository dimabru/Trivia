#define _CRT_SECURE_NO_WARNINGS
#include "general.h"
#include "menus.h"
#include "play.h"
//#include "MinUnit.h"
#include "vld.h"

/*MU_TEST(test_getUsers)
{
	user* temp;
	int* size;
	temp=getUsers(&size);
	if ((size == NULL&&temp != NULL) || (size != NULL&&temp == NULL))
		mu_fail("The size of the users in the file is not match the length of the list of users");
}
MU_TEST(test_getQuestions)
{

	long c = getQuestions("1");
	mu_assert(c == 1, "success");
}*/
int main()
{
	int num,i,size=0;
	//in menus
	//MU_RUN_SUITE(test_getUsers);
	//MU_REPORT();
	//first_menu();
	searchUser("123");
	//start_to_play();
	//user *list = getUsers(&size);
	//printUserList(list, size);
	//printf("%s\n", list[0].firstName);
	
	
	printf("=============================\n");
	printf("bye bye enter any key to exit\n");
	printf("=============================\n");
	_getch();

	return 0;
}

