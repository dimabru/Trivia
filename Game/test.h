#define _CRT_SECURE_NO_WARNINGS
#ifndef _test
#define _test
#include "general.h"
#include "files.h"
#include "MinUnit.h"
#define QNUM 10

void testQuestions();
MU_TEST(test_resetAll)
{
	resetAll();
}
MU_TEST(test_getavg_f)
{
	int test;
	test = getAverage();
	mu_check(!test);
}
MU_TEST(test_GetUsers)
{
	user *temp;
	int* size;
	temp = getUsers(&size);
	mu_check(temp == NULL);
}
MU_TEST(test_searchUser)
{
	user temp;
	temp = searchUser("12443");
	mu_check(temp.average == -1);
}
MU_TEST(test_addUser)
{
	user list;
	strcpy(list.ID, "123");
	list.average = 12;
	strcpy(list.firstName, "first_test");
	strcpy(list.lastName, "last_test");
	list.highScore = 12;
	strcpy(list.password, "pass_test");
	list.scoreList = malloc(sizeof(1));
	list.scoreList[0] = 1;
	list.userType = student;
	list.gamesPlayed = 1;

	mu_check(addUser(list) == 1);

}
MU_TEST(test_getavg_t)
{
	int test;
	test = getAverage();
	mu_check(test == 12);
}
MU_TEST(test_GetUsers_S)
{
	user *temp;
	int* size;
	temp = getUsers(&size);
	mu_check(temp != NULL);
}
MU_TEST(test_searchUser_S)
{
	user temp;
	temp = searchUser("123");
	mu_check(temp.average != -1);
}

MU_TEST(test_resetQuestion)
{
	resetQuestions();
}
MU_TEST(test_GetQuestions)
{
	question *temp;
	int* size;
	temp = getQuestions(&size);
	mu_check(temp == NULL);
}
MU_TEST(test_searchQuestion)
{
	question temp;
	temp = searchQuestion(1);
	mu_check(temp.ID == -1);
}
MU_TEST(test_addQuestion)
{
	fakeAnswer fa;
	fa.fakeAmount = 1;
	strcpy(fa.fakeList[0], "FakeAnswer1");
	fa.ID = 1;
	question list;
	strcpy(list.answer, "Answer1");
	list.answered = 0;
	list.ID = 1;
	list.level = 1;
	strcpy(list.str, "Question1");
	mu_check(addQuestion(list, fa) == 1);

}
MU_TEST(test_GetQuestion_S)
{
	question *temp;
	int* size;
	temp = getQuestions(&size);
	mu_check(temp != NULL);
}
MU_TEST(test_searchQuestion_S)
{
	question temp;
	temp = searchQuestion(1);
	mu_check(temp.ID != -1);
}
MU_TEST(test_getFakeAnswers){
	int* size;
	fakeAnswer* fa;
	fa = getFakeAnswers(&size);
	mu_check(fa != NULL);
}
MU_TEST(test_searchFakeAnswer)
{
	fakeAnswer fa;
	fa = searchFakeAnswer(1);
	mu_check(fa.ID == 1);
}
MU_TEST(test_getMessage_f)
{
	int* size;
	message* msg;
	msg = getMessages(&size);
	mu_check(msg == NULL);
}
MU_TEST(test_addMSG)
{
	message msg;
	strcpy(msg.ID, "1");
	strcpy(msg.msg, "msg_test");
	mu_check(addMessage(msg) == 1);
}
MU_TEST(test_getMessage)
{
	int* size;
	message* msg;
	msg = getMessages(&size);
	mu_check(msg != NULL);
}
MU_TEST(test_inputCheck_f)
{
	long test;
	test = inputCheck("9b");
	mu_check(test == -1);
}
MU_TEST(test_inputCheck_t)
{
	long test;
	test = inputCheck("99");
	mu_check(test != -1);
}
MU_TEST(test_view_current_record_f)
{
	int test;
	test = view_current_record("123");
	mu_check(test == -1);
}
MU_TEST(test_view_current_record_t)
{

	int test;
	test = view_current_record("123");
	mu_check(test != -1);
}
MU_TEST(test_sum_the_time)
{
	int test;
	test = sum_the_time();
	mu_check(!test);
}
MU_TEST(test_setUsers)
{
	user* list1;
	int *size2;
	list1 = getUsers(&size2);
	mu_check((setUsers(list1, size2) == 1 || setUsers(list1, size2) == 0));
}

MU_TEST(test_setQuestion)
{
	question* list1;
	int *size2;
	list1 = getQuestions(&size2);
	mu_check((setQuestions(list1, size2) == 1 || setQuestions(list1, size2) == 0));
}
MU_TEST(test_setfakeAnswer)
{
	fakeAnswer* list1;
	int *size2;
	list1 = getFakeAnswers(&size2);
	mu_check((setFakeAnswers(list1, size2) == 1 || setFakeAnswers(list1, size2) == 0));
}
MU_TEST(test_setMessages)
{
	message* list1;
	int *size2;
	list1 = getMessages(&size2);
	mu_check((setMessages(list1, size2) == 1 || setMessages(list1, size2) == 0));
}
MU_TEST(test_whileNotInt_t)
{
	long test;
	test = whileNotInt("12");
	mu_check(test == 12);
}
MU_TEST(test_printUser_t)
{
	int test;
	user list;
	strcpy(list.ID, "123");
	list.average = 12;
	strcpy(list.firstName, "rre");
	strcpy(list.lastName, "Sukrun");
	list.highScore = 12;
	strcpy(list.password, "ko89");
	list.scoreList = 0;
	list.userType = student;
	list.gamesPlayed = 0;
	test = printUser(list);
	mu_check(test == 1);
}
MU_TEST(test_printStudent_t)
{
	int test;
	user list;
	strcpy(list.ID, "123");
	list.average = 12;
	strcpy(list.firstName, "studentTest");
	strcpy(list.lastName, "studentTest2");
	list.highScore = 12;
	strcpy(list.password, "passTest");
	list.scoreList = 0;
	list.userType = student;
	list.gamesPlayed = 0;
	test = printStudent(list);
	mu_check(test == 1);
}

MU_TEST(test_printQuestion_t)
{
	int test;
	question list;
	strcpy(list.answer, "Answer1");
	list.answered = 0;
	list.ID = 1;
	list.level = 1;
	strcpy(list.str, "Question1");
	test = printQuestion(list);
	mu_check(test == 1);
}

MU_TEST(test_SetBest)
{
	best* list;
	int size = 1;
	list = malloc(sizeof(best)* 1);
	list[0].bestResult = 12;
	strcpy(list[0].ID, "123");
	mu_check(setBest(list, size));
}
MU_TEST(test_getBestResult_t)
{
	int *size;
	best* b_test;
	b_test = getBest(&size);
	mu_check(size == 1);

}
MU_TEST(test_getBestResult_f)
{
	int *size;
	best* b_test;
	b_test = getBest(&size);
	mu_check(size == 0);
}

MU_TEST(test_resetScores_t)
{
	mu_check(resetScores() == 1);
}
MU_TEST(set_Message_first)
{
	message* list;
	int size = 1;
	list = malloc(sizeof(message)* 1);
	strcpy(list[0].ID, "123");
	strcpy(list[0].msg, "test_msg");
	mu_check(setMessages(list, size));
}
MU_TEST(test_getMessage_first)
{
	int *size;
	message* msg_test;
	msg_test = getMessages(&size);
	mu_check(size == 1);
}


/*MU_TEST(test_setInstructions)
{
char* test_inst=NULL;
strcpy(*test_inst, "test");
mu_check(setInstructions(test_inst));
}*/
/*MU_TEST(test_getMessage_first)
{
int *size;
message* msg_test;
msg_test = getMessages(&size);
mu_check(size == 1);
}*/



MU_TEST_SUITE(test_MSG_firstFunctions)
{
	MU_RUN_TEST(set_Message_first);
	MU_RUN_TEST(test_getMessage_first);
}
MU_TEST_SUITE(test_UserFunctions)
{
	MU_RUN_TEST(resetUsers);
	MU_RUN_TEST(test_GetUsers);
	MU_RUN_TEST(test_searchUser);
	MU_RUN_TEST(test_addUser);
	MU_RUN_TEST(test_GetUsers_S);
	MU_RUN_TEST(test_searchUser_S);
}

MU_TEST_SUITE(test_QuestionsFunctions)
{
	MU_RUN_TEST(resetQuestions);
	MU_RUN_TEST(test_GetQuestions);
	MU_RUN_TEST(test_searchQuestion);
	MU_RUN_TEST(test_addQuestion);
	MU_RUN_TEST(test_GetQuestion_S);
	MU_RUN_TEST(test_searchQuestion_S);
}
MU_TEST_SUITE(test_MSGFunctions)
{
	MU_RUN_TEST(resetAll);
	MU_RUN_TEST(test_getMessage_f);
	MU_RUN_TEST(test_addMSG);
	MU_RUN_TEST(test_getMessage);
}
MU_TEST_SUITE(test_generalFunctions1)
{
	MU_RUN_TEST(test_inputCheck_f);
	MU_RUN_TEST(test_inputCheck_t);
}
MU_TEST_SUITE(test_generalFunctions2)
{
	MU_RUN_TEST(test_resetAll);
	MU_RUN_TEST(test_getavg_f);
	MU_RUN_TEST(test_addUser);
	MU_RUN_TEST(test_getavg_t);
}
MU_TEST_SUITE(test_generalFunctions3)
{
	MU_RUN_TEST(test_whileNotInt_t);
	MU_RUN_TEST(test_printUser_t);
	MU_RUN_TEST(test_printStudent_t);
	MU_RUN_TEST(test_printQuestion_t);
	MU_RUN_TEST(test_resetScores_t);
}
/*MU_TEST_SUITE(test_studentFunctions)
{
MU_RUN_TEST(test_view_current_record_f);
MU_RUN_TEST(test_addUser);
MU_RUN_TEST(test_view_current_record_t);
}*/
MU_TEST_SUITE(test_TimeCalculateFunctions)
{
	MU_RUN_TEST(test_sum_the_time);
}
MU_TEST_SUITE(test_setUsersFunction)
{
	MU_RUN_TEST(test_resetAll);
	MU_RUN_TEST(test_addUser);
	MU_RUN_TEST(test_setUsers);

}
MU_TEST_SUITE(test_setQuestionsFunction)
{
	MU_RUN_TEST(test_resetAll);
	MU_RUN_TEST(test_addQuestion);
	MU_RUN_TEST(test_setQuestion);
}

MU_TEST_SUITE(test_setFakeAnswersFunction)
{
	MU_RUN_TEST(test_resetAll);
	MU_RUN_TEST(test_addQuestion);
	MU_RUN_TEST(test_setfakeAnswer);

}
MU_TEST_SUITE(test_setMessagesFunction)
{
	MU_RUN_TEST(test_addMSG);
	MU_RUN_TEST(test_setMessages);
}
MU_TEST_SUITE(test_ResultsFunction)
{
	MU_RUN_TEST(test_view_current_record_f);
	MU_RUN_TEST(test_getBestResult_f);
	MU_RUN_TEST(test_SetBest);
	MU_RUN_TEST(test_view_current_record_t);
	MU_RUN_TEST(test_getBestResult_t);
}
#endif