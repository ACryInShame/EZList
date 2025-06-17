#pragma once
#include "ListNode.hpp"

template <typename T>
class EZList
{
	public:
		EZList();
		EZList(bool TRADIONAL);
		EZList(T NewData);
		EZList(T NewData,bool TRADIONAL);

		//Get Functions
		T operator[] (int);
		int GetLength();
		ListNode<T>* GetLastNode();
		bool GetTraditional();

		//Add Functions
		void Add(T NewData);
		void Add(T NewData, int Index);

		//Remove Functions
		//void Remove();
	private:
		ListNode<T>* Header;
		ListNode<T>* Ender;
		int Length;

		//Low index is 0 or 1 based on if this is a tradational index where 0 is the first node or non-traditional where 1 is.
		bool Traditional = true;
		int LowIndex = 0;
};

template<typename T>
EZList<T>::EZList()
{
	Header = nullptr;
	Ender = nullptr;
	Length = 0;

	if (Traditional)
		LowIndex = 0;
	else
		LowIndex = 1;
}

template<typename T>
inline EZList<T>::EZList(bool TRADIONAL)
{
	Header = nullptr;
	Ender = nullptr;
	Length = 0;

	Traditional = TRADIONAL;
	if (Traditional)
		LowIndex = 0;
	else
		LowIndex = 1;
}

template<typename T>
EZList<T>::EZList(T NewData)
{
	Header = new ListNode<T>(NewData);
	Ender = Header;
	Length = 1;

	if (Traditional)
		LowIndex = 0;
	else
		LowIndex = 1;
}

template<typename T>
inline EZList<T>::EZList(T NewData, bool TRADIONAL)
{
	Header = new ListNode<T>(NewData);
	Ender = Header;
	Length = 1;

	Traditional = TRADIONAL;
	if (Traditional)
		LowIndex = 0;
	else
		LowIndex = 1;
}

template<typename T>
T EZList<T>::operator[](int Index)
{
	//TODO: change to allow both ends of list for fast indexing
	try
	{
		if (Index < LowIndex)  
			throw std::runtime_error("requested index is less then lowest index");
		if (Index > Length)
			throw std::runtime_error("requested index outside of EZList");

		ListNode<T>* CurrentNode = Header;

		for (size_t i = LowIndex; i < Index; i++)
		{
			CurrentNode = CurrentNode->GetNextNode();
		}

		return CurrentNode->GetData();
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Caught error: " << e.what() << std::endl;
		exit(1); // Stops program from running further.
	}
}

template<typename T>
inline int EZList<T>::GetLength()
{
	return Length;
}

template<typename T>
ListNode<T>* EZList<T>::GetLastNode()
{
	return Ender;
}

template<typename T>
inline bool EZList<T>::GetTraditional()
{
	return Traditional;
}

template<typename T>
inline void EZList<T>::Add(T NewData)
{
	//todo: 
	if (Ender == nullptr && Header == nullptr)
	{
		Header = new ListNode<T>(NewData);
		Ender = Header;
	}
	else
	{
		ListNode<T>* Holder = Ender;
		Ender = new ListNode<T>(NewData);
		Holder->SetNextNode(Ender);
	}

	Length++;
}

template<typename T>
inline void EZList<T>::Add(T NewData, int Index)
{
	Length++;

	//create new node
	ListNode<T>* NewNode = new ListNode<T>(NewData);

	//replace Header
	if (Index == 0)
	{
		Header->SetPreviousNode(NewNode);
		NewNode->SetNextNode(Header);
		Header = NewNode;
		return;
	}

	//replace Ender
	if (Index == Length)
	{
		Ender->SetNextNode(NewNode);
		NewNode->SetPreviousNode(Ender);
		Ender = NewNode;
		return;
	}
	
	//find index location, -1 for the node before wanted index
	ListNode<T>* Holder = Header;
	for (size_t i = LowIndex; i < Index-1; i++)
	{
		Holder = Holder->GetNextNode();
	}

	NewNode->SetNextNode(Holder->GetNextNode());
	NewNode->SetPreviousNode(Holder);
	Holder->SetNextNode(NewNode);
}
