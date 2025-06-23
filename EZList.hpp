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
		~EZList();

		//Get Functions
		const T& operator[] (int) const;
		T& operator[] (int);
		int GetLength();
		ListNode<T>* GetLastNode();
		bool GetTraditional();

		//Add Functions
		void Add(T NewData);
		void Add(T NewData, int Index);

		//Remove Functions
		T Remove(int);
		void Delete(int);


		//Todo
		// Delete / clear
		// swap two elements
		// Sort
		// Merge (already sorted lists)
		// splice "Transfers elements from x into the container, inserting them at position."
		// Unique / Add Unique
		// reverse

	private:
		ListNode<T>* Header;
		ListNode<T>* Ender;
		int Length;

		//Low index is 0 or 1 based on if this is a tradational index where 0 is the first node or non-traditional where 1 is.
		bool Traditional = true;
		int LowIndex = 0;

		ListNode<T>* GetNodeAtIndex(int Index) const;
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
inline EZList<T>::~EZList()
{
	if (Header == nullptr) return;

	ListNode<T>* Holder = Ender;
	while (Holder != nullptr && Holder != Header)
	{
		ListNode<T>* PreviousNode = Holder->GetPreviousNode();
		delete Holder;
		Holder = PreviousNode;
	}
	delete Header;
	Header = nullptr;
	Ender = nullptr;
}

template<typename T>
const T& EZList<T>::operator[](int Index) const
{
	ListNode<T>* CurrentNode = GetNodeAtIndex(Index);
	return CurrentNode->GetData();
}

template<typename T>
inline T& EZList<T>::operator[](int Index)
{
	return 	GetNodeAtIndex(Index)->GetDataRef();
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
	if (Index == LowIndex)
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
	ListNode<T>* Holder = GetNodeAtIndex(Index-1);

	NewNode->SetNextNode(Holder->GetNextNode());
	NewNode->SetPreviousNode(Holder);
	Holder->SetNextNode(NewNode);
}

template<typename T>
inline T EZList<T>::Remove(int Index)
{
	ListNode<T>* Holder = GetNodeAtIndex(Index);
	T Data = Holder->GetData();

	ListNode<T>* PreviousNode = Holder->GetPreviousNode();
	ListNode<T>* NextNode = Holder->GetNextNode();

	PreviousNode->SetNextNode(NextNode);
	NextNode->SetPreviousNode(PreviousNode);

	delete Holder;
	Length--;
	return Data;
}

template<typename T>
inline void EZList<T>::Delete(int Index)
{
	if (Index < LowIndex || Index > Length-LowIndex)
		throw std::runtime_error("Deleted index outside of EZList");
	ListNode<T>* Holder GetNodeAtIndex(Index);
	Holder->GetPreviousNode()->SetNextNode(
		Holder->GetNextNode()
		);

	Length--;
	delete Holder;
}

template<typename T>
inline ListNode<T>* EZList<T>::GetNodeAtIndex(int Index) const
{
	if (Index < LowIndex || Index > LowIndex + Length -1)  
		throw std::out_of_range("requested Index outside of bounds");

	ListNode<T>* CurrentNode = Header;
	for (int i = LowIndex; i < Index; i++)
	{
		CurrentNode = CurrentNode->GetNextNode();
		if (!CurrentNode)
			throw std::runtime_error("List corrupted: node pointer null");
	}

	return CurrentNode;
}