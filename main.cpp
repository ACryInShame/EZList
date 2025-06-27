#include "EZList.hpp"

#include <iostream>

using namespace std;

void WaitToClear();
void InitTest(EZList<int>* TestList);
void FillTest(EZList<int>* TestList);
void PrintTest(EZList<int>* TestList);
void GetTests(EZList<int>* TestList);
void AddTests(EZList<int>* TestList);
void RemoveTest(EZList<int>* TestList);
void ChangeDataTest(EZList<int>* TestList);
void MakeUniqueTest(EZList<int>* TestList);


int main()
{
	EZList<int> List1;
	EZList<int> List2 (false);
	EZList<int> List3 (1);
	EZList<int> List4 (1, false);

	cout << "===Initalization Test===" << endl;
	InitTest(&List1);
	InitTest(&List2);
	InitTest(&List3);
	InitTest(&List4);

	WaitToClear();

	cout << "===Fill and Print Test [Tradional]===" << endl;
	FillTest(&List1);
	PrintTest(&List1);

	WaitToClear();

	cout << "=== Fill and Print Test [Non-Tradional] ===" << endl;
	FillTest(&List2);
	PrintTest(&List2);

	WaitToClear();

	cout << "=== Get Tests ===" << endl;
	cout << "Tradional List" << endl;
	GetTests(&List1);
	cout << endl;
	cout << "non-Tradional List" << endl;
	GetTests(&List2);

	WaitToClear();
	cout << "=== Add Tests ===" << endl;
	cout << "Tradional" << endl;
	AddTests(&List1);
	cout << endl << "non-Tradional" << endl;
	AddTests(&List2);

	WaitToClear();
	cout << "=== Remove Test Tradional ===" << endl;
	RemoveTest(&List1);
	cout << "=== Remove Test Non-Tradional ===" << endl;
	RemoveTest(&List2);

	WaitToClear();

	cout << "=== Change Data Test Tradional ===" << endl;
	ChangeDataTest(&List1);

	WaitToClear();

	cout << "=== Change Data Test Non-Tradional ===" << endl;
	ChangeDataTest(&List2);

	WaitToClear();

	cout << "=== MakeUniqueTest  ===";
	MakeUniqueTest(&List1);


	WaitToClear();
	return 0;
}

void WaitToClear()
{
	cout << "Press Enter to continue";
	cout << endl;
	cin.ignore();
	system("cls");
	system("clear");
}

void InitTest(EZList<int>* TestList)
{
	cout << "--Testing Initilization--" << endl ;
	cout << "Is Tradional? : " << TestList->GetTraditional() << endl;
	cout << "Has a node? :";
	if (TestList->GetLastNode() != nullptr)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	cout << endl << endl;
}

void FillTest(EZList<int>* TestList)
{
	//Fill List and test length functions [ Tradional list]
	int length = 5;
	for (int i = 0; i < length; i++)
	{
		TestList->Add(i);
		cout << endl;
		cout << i << " Added to list";
	}
	cout << endl;
	cout << "Length is " << TestList->GetLength();
	cout << endl;
	cout << endl;
}

void PrintTest(EZList<int>* TestList)
{
	//print list
	cout << endl;
	for (int i = TestList->GetLowIndex(); i <= TestList->GetLowIndex() + TestList->GetLength() - 1; i++)
	{
		cout << (*TestList)[i] << " ";
	}
	cout << endl;
}

void GetTests(EZList<int>* TestList)
{
	cout << "Test get last node -> Get Data : " << TestList->GetLastNode()->GetData();
	cout << endl;
	cout << "Test Get Legnth : " << TestList->GetLength();
	cout << endl;
	cout << "Test Get Traditional : " << TestList->GetTraditional();
	cout << endl;
}

void AddTests(EZList<int>* TestList)
{
	TestList->Add(99);
	cout << "Test Add : ";
	PrintTest(TestList);
	cout << endl;
	cout << endl;
	TestList->Add(88,3);
	cout << "Test Add [index(3)] :";
	PrintTest(TestList);
	cout << endl;
	cout << endl;
}

void RemoveTest(EZList<int>* TestList)
{
	cout << "Remove Test: Index 3";
	cout << endl;
	cout << "List Before Removal";
	PrintTest(TestList);
	int RemovedData = TestList->Remove(3);
	cout << "Removed " << RemovedData << " From List";
	cout << endl;
	cout << "current list";
	PrintTest(TestList);
}

void ChangeDataTest(EZList<int>* TestList)
{
	EZList<int>& Ref = *TestList;
	cout << endl;
	cout << "before Change";
	cout << endl;
	PrintTest(TestList);

	Ref[3] = 55;

	cout << "After Change";
	cout << endl;
	PrintTest(TestList);
}

void MakeUniqueTest(EZList<int>* TestList)
{
	TestList->Clear();
	for (int i = 0; i < 5; i++)
	{
		for (int i = 0 ; i <5; i++)
			TestList->Add(i);
	}
	cout << endl;
	cout << "before run Print ";
	cout << endl;
	PrintTest(TestList);
	cout << endl;
	cout << "-------------";
	cout << endl;

	cout << "After Run";
	TestList->MakeUnique();
	PrintTest(TestList);
}

