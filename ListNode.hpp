#pragma once

template<typename T>
class ListNode
{
	public:
		ListNode();
		ListNode(T NewData);
		ListNode(T NewData, ListNode*);

		T GetData();
		T& GetDataRef();
		void SetData(T);

		ListNode* GetNextNode();
		void SetNextNode(ListNode*);

		ListNode* GetPreviousNode();
		void SetPreviousNode(ListNode*);

	private:
		T Data;
		ListNode* PreviousNode;
		ListNode* NextNode;
};

template<typename T>
inline ListNode<T>::ListNode()
{
	PreviousNode = nullptr;
	NextNode = nullptr;
}

template<typename T>
ListNode<T>::ListNode(T NewData)
{
	Data = NewData;
	PreviousNode = nullptr;
	NextNode = nullptr;
}

template<typename T>
ListNode<T>::ListNode(T NewData, ListNode* NewNextNode)
{
	Data = NewData;
	NextNode = NewNextNode;
}

template<typename T>
T ListNode<T>::GetData()
{
	return Data;
}

template<typename T>
inline T& ListNode<T>::GetDataRef()
{
	return Data;
}

template<typename T>
void ListNode<T>::SetData(T NewData)
{
	Data = NewData;
}

template<typename T>
void ListNode<T>::SetNextNode(ListNode* NewNode)
{
	NextNode = NewNode;
}

template<typename T>
ListNode<T>* ListNode<T>::GetNextNode()
{
	return NextNode;
};

template<typename T>
void ListNode<T>::SetPreviousNode(ListNode* NewNode)
{
	PreviousNode = NewNode;
}

template<typename T>
ListNode<T>* ListNode<T>::GetPreviousNode()
{
	return PreviousNode;
};