#pragma once
#include "ListNode.hpp"
#include <cassert>

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
		int GetLength();
		ListNode<T>* GetLastNode();
		bool GetTraditional();

		//Add Functions
		void Add(T NewData);
		void Add(T NewData, int Index);

		//Remove Functions
		T Remove(int);
		void Delete(int);
		void Clear();

		//Test Functions
		bool IsEmpty();

		//Operations
		T& operator[] (int);
		void Swap(int Index1, int Index2);


		//Todo
		// swap two elements
		// Sort
		// Merge (already sorted lists)
		// splice "Transfers elements from x into the container, inserting them at position."
		// Unique / Add Unique
		// reverse

	private:
		ListNode<T>* Header;
		ListNode<T>* Footer;
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
	Footer = nullptr;
	Length = 0;

	// This if is not needed but is kept in case code changes to keep things readable.
	if (Traditional)
		LowIndex = 0;
	else
		LowIndex = 1;
}

template<typename T>
inline EZList<T>::EZList(bool TRADIONAL)
{
	Header = nullptr;
	Footer = nullptr;
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
	Footer = Header;
	Length = 1;

	// This if is not needed but is kept in case code changes to keep things readable.
	if (Traditional)
		LowIndex = 0;
	else
		LowIndex = 1;
}

template<typename T>
inline EZList<T>::EZList(T NewData, bool TRADIONAL)
{
	Header = new ListNode<T>(NewData);
	Footer = Header;
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
	Clear();
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
inline void EZList<T>::Swap(int Index1, int Index2)
{
	//if same index, do nothing
	if (Index1 == Index2) return;

	//Get Both Nodes
	ListNode<T>* Node1 = GetNodeAtIndex(Index1);
	ListNode<T>* Node2 = GetNodeAtIndex(Index2);

	// checks for null pointers but should not ever trigger if GetNodeAtIndex is working properly
	assert(Node1 != nullptr && Node2 != nullptr && "Null node encountered during swap.");

	//Update surounding nodes of Node1
	//If Null or Node2, Skip
	if (Node1->GetPreviousNode() != nullptr && Node1->GetPreviousNode() != Node2)
		Node1->GetPreviousNode()->SetNextNode(Node2);
	if (Node1->GetNextNode() != nullptr && Node1->GetNextNode() != Node2)
		Node1->GetNextNode()->SetPreviousNode(Node2);
	// Check Header and Footer
	if (Node1 == Header)
		Header = Node2;
	if (Node1 == Footer)
		Footer = Node2;

	//Update surounding nodes of Node2
	//If Null or Node2, Skip
	if (Node2->GetPreviousNode() != nullptr && Node2->GetPreviousNode() != Node1)
		Node2->GetPreviousNode()->SetNextNode(Node1);
	if (Node2->GetNextNode() != nullptr && Node2->GetNextNode() != Node1)
		Node2->GetNextNode()->SetPreviousNode(Node1);
	// Check Header and Footer
	if (Node2 == Header)
		Header = Node1;
	if (Node2 == Footer)
		Footer = Node1;

	//update Node pointers
	//hold node 1 points for change over
	ListNode<T>* HolderNext = Node1->GetNextNode();
	ListNode<T>* HolderPre = Node1->GetPreviousNode();

	//set Node1 Pointers
	if (Node2->GetNextNode() == Node1) // Check if Adjacent to avoid pointer issues
		Node1->SetNextNode(Node2);
	else
		Node1->SetNextNode(Node2->GetNextNode());

	if (Node2->GetPreviousNode() == Node1) // Check if Adjacent to avoid pointer issues
		Node1->SetPreviousNode(Node2);
	else
		Node1->SetPreviousNode(Node2->GetPreviousNode());

	//set Node2 Pointers
	if (HolderNext == Node2) // Check if Adjacent to avoid pointer issues
		Node2->SetNextNode(Node1);
	else
		Node2->SetNextNode(HolderNext);

	if (HolderPre == Node2) // Check if Adjacent to avoid pointer issues
		Node2->SetPreviousNode(Node1);
	else
		Node2->SetPreviousNode(HolderPre);
}

template<typename T>
inline int EZList<T>::GetLength()
{
	return Length;
}

template<typename T>
ListNode<T>* EZList<T>::GetLastNode()
{
	return Footer;
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
	if (Footer == nullptr && Header == nullptr)
	{
		Header = new ListNode<T>(NewData);
		Footer = Header;
	}
	else
	{
		ListNode<T>* Holder = Footer;
		Footer = new ListNode<T>(NewData);
		Holder->SetNextNode(Footer);
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

	//replace Footer
	if (Index == Length)
	{
		Footer->SetNextNode(NewNode);
		NewNode->SetPreviousNode(Footer);
		Footer = NewNode;
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
inline void EZList<T>::Clear()
{
	if (Header == nullptr) return;

	ListNode<T>* Holder = Footer;
	while (Holder != nullptr && Holder != Header)
	{
		ListNode<T>* PreviousNode = Holder->GetPreviousNode();
		delete Holder;
		Holder = PreviousNode;
	}
	delete Header;
	Header = nullptr;
	Footer = nullptr;

	Length = 0;
	LowIndex = Traditional ? 0 : 1;
}

template<typename T>
inline bool EZList<T>::IsEmpty()
{
	if (Length > 0)
		return false;
	return true;
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