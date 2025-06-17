#include "EZList.hpp"

#include <iostream>

using namespace std;

void InitTest(EZList<int>* TestList);
void WaitToClear();
void FillTest(EZList<int>* TestList);
void FillTestNT(EZList<int>* TestList);
void PrintTest(EZList<int>* TestList);
void PrintTestNT(EZList<int>* TestList);
void GetTests(EZList<int>* TestList);
void AddTests(EZList<int>* TestList);
void AddTestsNT(EZList<int>* TestList);

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

	cout << "===Fill and Print Test [Non-Tradional]===" << endl;
	FillTestNT(&List2);
	PrintTestNT(&List2);

	WaitToClear();
	
	cout << "Tradional" << endl;
	GetTests(&List1);

	cout << endl << "non-Tradional" << endl;
	GetTests(&List2);

	WaitToClear();

	cout << "Tradional" << endl;
	AddTests(&List1);
	cout << endl << "non-Tradional" << endl;
	AddTestsNT(&List2);

	WaitToClear();

	/*
	//add to start of list'
	cout << "\n";
	NewList.Add(99, 0);
	cout << "Length after add is " << NewList.GetLength();

	//print list
	for (size_t i = 0; i <= NewList.GetLength()-1; i++)
	{
		cout << "\n";
		cout << NewList[i];
	}
	/*
	cout << "\n";
	NewList.Add(14,3);
	cout << NewList[0];
	cout << "\n";
	cout << NewList[1];
	cout << "\n";
	cout << NewList[2];
	cout << "\n";
	cout << NewList[3];

	cout << "\n";
	cout << "End Test";
	cout << "\n\n\n\n\n\n";
	*/
	return 0;
}

void InitTest(EZList<int>* TestList)
{
	/*EZList();
	EZList(bool TRADIONAL);
	EZList(T NewData);
	EZList(T NewData,bool TRADIONAL);*/

	cout << "--Testing Initilization--" << endl ;
	cout << "Is Tradional? : " << TestList->GetTraditional() << endl;
	cout << "Has a node? :";
	if (TestList->GetLastNode() != nullptr)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	cout << endl << endl;
}

void WaitToClear()
{
	cout << "Press Enter to continue";
	cout << endl;
	cin.ignore();
	system("cls");
}

void FillTest(EZList<int>* TestList)
{
	//Fill List and test length functions [ Tradional list]
	int length = 5;
	for (size_t i = 0; i < length; i++)
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

void FillTestNT(EZList<int>* TestList)
{
	//Fill List and test length functions [ Tradional list]
	int length = 5;
	for (size_t i = 1; i <= length; i++)
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
	for (size_t i = 0; i <= TestList->GetLength()-1; i++)
	{
		cout << endl;
		cout << (*TestList)[i];
	}
	cout << endl;
}

void PrintTestNT(EZList<int>* TestList)
{
	//print list
	for (size_t i = 1; i <= TestList->GetLength(); i++)
	{
		cout << endl;
		cout << (*TestList)[i];
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

void AddTestsNT(EZList<int>* TestList)
{
	TestList->Add(99);
	cout << "Test Add : ";
	PrintTestNT(TestList);
	cout << endl;
	cout << endl;
	TestList->Add(88,3);
	cout << "Test Add [index(3)] :";
	PrintTestNT(TestList);
	cout << endl;
	cout << endl;
}
