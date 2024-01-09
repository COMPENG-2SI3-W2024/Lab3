#include "objPos.h"
#include "objPosStack.h"
#include "cmdQueue.h"

#include <cstdlib>
#include <ctime>

#define COUNT 10
#define LARGE_COUNT 20
#define TOTAL_ASSERT_COUNT 176

#include <iostream>
using namespace std;

objPosStack *StackUnderTest;
cmdQueue *QueueUnderTest;
int successCount;

void createNewStack();
void clearStack();
void createNewQueue();
void clearQueue();
objPos generateRandomPos();
char generateRandomChar();
void assert_equal(int, int);
void assert_equal(char, char);
void assert_equal(bool, bool);

// Turn this true once you are ready to test populateRandomElements() and generateObjects()
bool testSortReady = true;;




////////////////////////////////////
////////////////////////////////////
////////   STACK TESTERS   /////////
////////////////////////////////////
////////////////////////////////////

void testConstructorGetSize() {
	
	cout << "TEST: testConstructorGetSize" << endl;
	createNewStack();
	int expected = 0;
	int actual = StackUnderTest->size();	

	assert_equal(expected, actual);
	clearStack();
}



// PUSH, POP, and TOP
// PUSH, POP, and TOP
// PUSH, POP, and TOP

void testPushTenTop() {

	cout << "TEST: testPushTenTop" << endl;
	objPos itemArray[COUNT];
	objPos expected, actual;
	createNewStack();

	for(int i = 0; i < COUNT; i++)
	{
		itemArray[i] = generateRandomPos();
		StackUnderTest->push(itemArray[i]);
		
		expected = itemArray[i];
		actual = StackUnderTest->top();

		cout << "\tItem " << i << ": ";
		expected.printObjPos();		
		
		assert_equal(expected.getX(), actual.getX());
		assert_equal(expected.getY(), actual.getY());
		assert_equal(expected.getNum(), actual.getNum());
		assert_equal(expected.getPF(), actual.getPF());
		assert_equal(expected.getSym(), actual.getSym());

		cout<< "\tStack Size: " << i+1 << endl;
		assert_equal(StackUnderTest->size(), i+1);
	}
	
	clearStack();
}

void testPushTenPop() {

	cout << "TEST: testPushTenPop" << endl;
	objPos itemArray[COUNT];
	objPos expected, actual;
	createNewStack();

	for(int i = 0; i < COUNT; i++)
	{
		itemArray[i] = generateRandomPos();
		StackUnderTest->push(itemArray[i]);		
	}

	cout << "\tStack Size before Pop: " << StackUnderTest->size() << endl;
	assert_equal(StackUnderTest->size(), COUNT);

	for(int i = COUNT-1; i >= 0; i--)
	{
		expected = itemArray[i];
		actual = StackUnderTest->pop();

		cout << "\tItem " << i << ": ";
		expected.printObjPos();		
		
		assert_equal(expected.getX(), actual.getX());
		assert_equal(expected.getY(), actual.getY());
		assert_equal(expected.getNum(), actual.getNum());
		assert_equal(expected.getPF(), actual.getPF());
		assert_equal(expected.getSym(), actual.getSym());

		cout<< "\tStack Size: " << i << endl;
		assert_equal(StackUnderTest->size(), i);	
	}
	
	clearStack();
}


// RANDOM GEN and SORT
// RANDOM GEN and SORT
// RANDOM GEN and SORT

void testTwentyRandomGenerationAndSort() {

	cout << "TEST: testRandomGenerationAndSort" << endl;
	bool expected, actual = true;
	objPos curr, prev;

	createNewStack();

	StackUnderTest->populateRandomElements(LARGE_COUNT);
	prev = StackUnderTest->pop();

	for(int i = 0; i < LARGE_COUNT - 1; i++)
	{
		curr = StackUnderTest->pop();

		cout << "\tItem " << i << "," << i+1 << ": " << endl << "\t";
		prev.printObjPos();		
		cout << "\t";
		curr.printObjPos();	
		
		expected = ((prev.getNum() / 10) <= (curr.getNum() / 10));
		
		assert_equal(expected, actual);		

		prev = curr;
	}
	
	clearStack();
}

////////////////////////////////////
////////////////////////////////////
////////   QUEUE TESTERS   /////////
////////////////////////////////////
////////////////////////////////////

void testQueueConstructorGetSize() {
	
	cout << "TEST: testQueueConstructorGetSize" << endl;
	createNewQueue();
	int expected = 0;
	int actual = QueueUnderTest->getSize();	

	assert_equal(expected, actual);
	clearQueue();
}

void testEnqueueDequeueGetSizeTen() {
	
	cout << "TEST: testEnqueueGetSize" << endl;
	createNewQueue();
	char itemArray[COUNT];
	char expected, actual;

	for(int i = 0; i < COUNT; i++)
	{
		itemArray[i] = generateRandomChar();
		QueueUnderTest->enqueue(itemArray[i]);
	}

	cout << "\tQueue Size before Dequeue: " << QueueUnderTest->getSize() << endl;
	assert_equal(QueueUnderTest->getSize(), COUNT);

	for(int i = 0; i < COUNT; i++)
	{
		expected = QueueUnderTest->dequeue();
		actual = itemArray[i];
		cout << "\tItem" << i << ": (" << expected << ", " << actual << ")" << endl;

		assert_equal(expected, actual);
	}

	cout << "\tQueue Size after Dequeue: " << QueueUnderTest->getSize() << endl;
	assert_equal(QueueUnderTest->getSize(), 0);

	clearQueue();
}

void testEnqueueDequeueGetSizeTwenty() {
	
	cout << "TEST: testEnqueueGetSize" << endl;
	createNewQueue();
	char itemArray[LARGE_COUNT];
	char expected, actual;

	for(int i = 0; i < LARGE_COUNT; i++)
	{
		itemArray[i] = generateRandomChar();
		QueueUnderTest->enqueue(itemArray[i]);
	}

	cout << "\tQueue Size before Dequeue: " << QueueUnderTest->getSize() << endl;
	assert_equal(QueueUnderTest->getSize(), LARGE_COUNT);

	for(int i = 0; i < LARGE_COUNT; i++)
	{
		expected = QueueUnderTest->dequeue();
		actual = itemArray[i];
		cout << "\tItem" << i << ": (" << expected << ", " << actual << ")" << endl;

		assert_equal(expected, actual);
	}

	cout << "\tQueue Size after Dequeue: " << QueueUnderTest->getSize() << endl;
	assert_equal(QueueUnderTest->getSize(), 0);
	
	clearQueue();
}

bool runAllTests(int argc, char const *argv[]) {
	
	// objPosStack Testers
	cout << "[STACK TESTER STARTED]" << endl;
    testConstructorGetSize();
	testPushTenTop();
	testPushTenPop();

	if(testSortReady)
	{
		testTwentyRandomGenerationAndSort();
	}
	cout << "[STACK TESTER ENDED]" << endl << endl;

	// cmdQueue Testers
	cout << "[QUEUE TESTER STARTED]" << endl;
	testQueueConstructorGetSize();
	testEnqueueDequeueGetSizeTen();
	testEnqueueDequeueGetSizeTwenty();
	cout << "[QUEUE TESTER ENDED]" << endl << endl;

	if(successCount != TOTAL_ASSERT_COUNT) 
		return false;
	else 
		return true;
}

int main(int argc, char const *argv[]) {
  	
	srand(time(NULL));
	successCount = 0;
	bool successCode = runAllTests(argc, argv);
	if(successCode)	cout << endl << "Passed All Tests" << endl;
	else			cout << "Failed Tests, Check Failure" << endl;	
	cout << "Assertion Score: " << successCount << " / " << TOTAL_ASSERT_COUNT << endl;	

	return successCode? EXIT_SUCCESS : EXIT_FAILURE;
}

void clearStack()
{
	delete StackUnderTest;
	StackUnderTest = NULL;	
}

void createNewStack()
{
	if(StackUnderTest != NULL) clearStack();
	StackUnderTest = new objPosStack();
}

void clearQueue()
{
	delete QueueUnderTest;
	QueueUnderTest = NULL;	
}

void createNewQueue()
{
	if(QueueUnderTest != NULL) clearQueue();
	QueueUnderTest = new cmdQueue();
}


objPos generateRandomPos()
{
	objPos temp;

	temp.setX(rand() % 100);
	temp.setY(rand() % 100);
	temp.setNum(rand() % 500);
	temp.setPF(rand() % 26 + 'a');
	temp.setSym(rand() % 26 + 'A');

	return temp;
}

char generateRandomChar()
{
	char candidate;

	if(rand() % 2 == 0)	candidate = rand() % 26 + 'a';
	else				candidate = rand() % 26 + 'A';

	return candidate;
}


void assert_equal(int a, int b)
{
	bool result = (a == b);
	if(result)	
		successCount++;
	else
	{
		cout << "\t\t[ASSERTION] Expected: " << a << ", but Actual: " << b << endl;		
	}
	//return result;
}

void assert_equal(char a, char b)
{
	bool result = (a == b);
	if(result)	
		successCount++;
	else
	{
		cout << "\t\tExpected: " << a << ", but Actual: " << b << endl;		
	}
	//return result;
}

void assert_equal(bool a, bool b)
{
	bool result = (a == b);
	if(result)	
		successCount++;
	else
	{
		if(a)
			cout << "\t\t[ASSERTION] Expected: TRUE, but Actual: FALSE" << endl;		
		else
			cout << "\t\t[ASSERTION] Expected: FALSE, but Actual: TRUE" << endl;		
	}
	//return result;
}