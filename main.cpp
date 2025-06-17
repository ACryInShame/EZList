#include "EZList.hpp"

#include <iostream>

using namespace std;

void InitTest(EZList<int>* TestList);

int main()
{
	EZList<int> List1;
	EZList<int> List2 (false);
	EZList<int> List3 (1);
	EZList<int> List4 (1, false);

	InitTest(&List1);
	InitTest(&List2);
	InitTest(&List3);
	InitTest(&List4);


	/*


	//Generate List
	EZList<int> NewList;
	cout << "Length is " << NewList.GetLength();

	//Fill List
	int length = 5;
	for (size_t i = 0; i <= length; i++)
	{
		NewList.Add(i);
		cout << "\n";
		cout << i << "Added to list";
	}
	cout << "Length is " << NewList.GetLength();
	cout << "\n";
	cout << "\n";

	//print list
	for (size_t i = 0; i <= NewList.GetLength()-1; i++)
	{
		cout << "\n";
		cout << NewList[i];
	}

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

	cout << "----Testing Initilization----" << endl ;
	cout << "Is Tradional? : " << TestList->GetTraditional() << endl;
	cout << "Has a node? :";
	if (TestList->GetLastNode() != nullptr)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	cout << endl << endl;
}