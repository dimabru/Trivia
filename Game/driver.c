#define _CRT_SECURE_NO_WARNINGS
#include "general.h"
#include "menus.h"
#include "play.h"
#include "student.h"
#include "MinUnit.h"
#include "vld.h"

void runAllSuite()
{
	MU_RUN_SUITE(test_UserFunctions);
	MU_RUN_SUITE(test_QuestionsFunctions);
	MU_RUN_SUITE(test_MSGFunctions);
	MU_RUN_SUITE(test_generalFunctions1);
	MU_RUN_SUITE(test_generalFunctions2);
	MU_RUN_SUITE(test_generalFunctions3);
	//MU_RUN_SUITE(test_studentFunctions);
	MU_RUN_SUITE(test_TimeCalculateFunctions);
	MU_RUN_SUITE(test_setUsersFunction);
	MU_RUN_SUITE(test_setQuestionsFunction);
	MU_RUN_SUITE(test_setFakeAnswersFunction);
	MU_RUN_SUITE(test_setMessagesFunction);
	resetAll();
}
void running_unit_tests()
{
	int *sizeQ, res, *sizeFA;
	question* listQ;
	fakeAnswer* listFA;
	listQ = getQuestions(&sizeQ);
	listFA = getFakeAnswers(&sizeFA);
	runAllSuite();
	MU_REPORT();
	res = setQuestions(listQ, sizeQ);
	res = setFakeAnswers(listFA, sizeFA);
}

int main()
{
	int selection;
	//=====================
	//Running the project:
	//=====================
	printf("Enter 0 for test mode, anything else to start the program\n");
	scanf("%d", &selection);
	if (selection) first_menu();
	else running_unit_tests();
	printf("=============================\n");
	printf("bye bye enter any key to exit\n");
	printf("=============================\n");
	_getch();
	return 0;
}
