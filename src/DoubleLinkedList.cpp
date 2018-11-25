// DoublyLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

template <class T>
class Node
{
public:
	// Members
	T* mData;
	Node* mNext;
	Node* mPrevious;
	
	// Simple Constructor
	Node(){
		mData = nullptr;
		mNext = nullptr;
		mPrevious = nullptr;
	}

	// Destructor for Node class
	~Node() {};

	// Constructor with data initialization
	Node(T* data)
	{
		mData = data;
		mNext = nullptr;
		mPrevious = nullptr;
	}
};

template <class T>
class DoublyLinkedList
{
public:
	// Members
	Node<T>* mHead;
	Node<T>* mTail;
	int mSize;

	// Constructor
	DoublyLinkedList()
	{
		mHead = nullptr;
		mTail = nullptr;
		mSize = 0;
	}

	// Destructor for DoublyLinkedList class
	~DoublyLinkedList()
	{
		// Deletes the nodes if there are any in the list
		if (mSize > 0)
		{
			int originalSize = mSize;
			for (int i = 0; i < originalSize; i++)
			{
				RemoveNodeAt(0);
			}
		}
	}

	// Return head data
	Node<T>* GetHead()
	{
		return mHead;
	}

	// Return tail data
	Node<T>* GetTail()
	{
		return mTail;
	}

	// Return the number of nodes
	int GetSize()
	{
		return mSize;
	}

	// Creates node with data at the start of the linked list
	void AddNodeAtHead(T* pData)
	{
		// Checks if this is the first node added to the list
		if (mSize == 0) 
		{
			addFirstNode(pData);
		}
		else
		{
			// Its not the first node in the list
			Node<T>* newNode = new Node<T>(pData);
			newNode->mNext = mHead;
			mHead->mPrevious = newNode;
			mHead = newNode;
		}
		// Adds a node to the size
		mSize++;
	}

	// Creates node with data at the end of the linked list
	void AddNodeAtTail(T* pData)
	{
		// Checks if this is the first node added to the list
		if (mSize == 0)
		{
			addFirstNode(pData);
		}
		else
		{
			// Its not the first node in the list
			Node<T>* newNode = new Node<T>(pData);
			newNode->mPrevious = mTail;
			mTail->mNext = newNode;
			mTail = newNode;
		}
		// Adds a node to the size
		mSize++;
	}

	// Returns node data at index
	Node<T>* GetNodeAt(int index)
	{
		// Checks if the list is empty or doesn't exists inside the list
		if (!isValidIndex(index))
		{
			return nullptr;
		}
		else
		{
			// Loops for each node in the list and gets the onde with the index
			Node<T>* node = mHead;
			for (int i = 0; i < mSize; i++)
			{
				if (i == index)
				{
					break;
				}
				node = node->mNext;
			}
			return node;
		}
	}

	// Remove node at index
	void RemoveNodeAt(int index)
	{
		// Checks if the list is empty or doesn't exists inside the list
		if (!isValidIndex(index))
		{
			return;
		}
		else
		{
			// Loops over the list to eliminate the node
			Node<T>* currentNode = mHead;
			for (int i = 0; i < mSize; i++)
			{
				// Checks if 
				if (i == index)
				{
					// Checks if the node is at the head
					if (!currentNode->mPrevious)
					{
						// Checks if there is another node to connect to the head
						if (currentNode->mNext)
						{
							mHead = currentNode->mNext;
							mHead->mPrevious = nullptr;
						}
						// This node is the only one in the list
						else
						{
							mHead = nullptr;
							mTail = nullptr;
						}
					}
					// Checks if the node is at the tail
					else if (!currentNode->mNext)
					{
						mTail = currentNode->mPrevious;
						mTail->mNext = nullptr;
					}
					// Any Intermediate
					else
					{
						currentNode->mPrevious->mNext = currentNode->mNext;
						currentNode->mNext->mPrevious = currentNode->mPrevious;
					}

					// Deletes the current node
					delete currentNode;
					break;
				}
				currentNode = currentNode->mNext;
			}
			// Decreases the size value
			mSize--;
		}
	}

	// Find and remove node via comparing data (return value is if removed or not)
	bool RemoveNode(T* pData)
	{
		bool deleted = false;
		// Checks if the linked list at least contains on object
		if (mSize > 0)
		{
			Node<T>* currentNode = mHead;
			// Loops over the linked list
			for (int i = 0; i < mSize; i++)
			{
				// Checks for the value to be compared and deletes it via its index
				if (currentNode->mData == pData)
				{
					RemoveNodeAt(i);
					deleted = true;
					break;
				}
				currentNode = currentNode->mNext;
			}
		}
		return deleted;
	}

	// Clones the current doubly linked list, creating a new independent one
	DoublyLinkedList<T>* Clone()
	{
		// Checks if the list has items in it
		if (mSize > 0)
		{
			DoublyLinkedList<T>* newList = new DoublyLinkedList<T>();
			// Loops over the size of the list, creates new instances of nodes and adds them to the new list
			Node<T>* currentNode = mHead;
			for (int i = 0; i < mSize; i++)
			{
				newList->AddNodeAtTail(currentNode->mData);
				currentNode = currentNode->mNext;
			}
			return newList;
		}
		else
		{
			// returns empty doubly linked list
			return new DoublyLinkedList<T>();
		}
	}

private:
	// Adds the first node to the list
	void addFirstNode(T* pData)
	{
		Node<T>* newNode = new Node<T>(pData);
		mHead = newNode;
		mTail = newNode;
	}

	// Checks if the index is accesible in the list
	bool isValidIndex(int index)
	{
		return mSize > 0 && index < mSize && index >= 0;
	}
};


int main()
{
	// Mock Data
	int data1 = 1;
	int data2 = 2;
	int data3 = 3;
	int data4 = 4;
	int data5 = 5;

	// Creates new Doubly Linked List
	DoublyLinkedList<int> myList;

	// Adds nodes to the list
	myList.AddNodeAtHead(&data1);
	myList.AddNodeAtHead(&data2);
	myList.AddNodeAtTail(&data3);
	myList.AddNodeAtHead(&data4);
	myList.AddNodeAtTail(&data5);
	// Final sequence: 4,2,1,3,5

	// gets the head and the tail
	Node<int>* head = myList.GetHead();
	Node<int>* tail = myList.GetTail();

	// gets the size of the linked list
	int listSize = myList.GetSize();

	// Get node at a specific index position
	Node<int>* nodeAt = myList.GetNodeAt(1);

	// Delete node at index
	//myList.RemoveNodeAt(2);
	//myList.RemoveNodeAt(0);

	//// Delete node via comparing
	//myList.RemoveNode(&data2);
	//myList.RemoveNode(&data3);

	// Clones the list
	DoublyLinkedList<int>* secondList = myList.Clone();
	
	// Cleans the memory of a deleted linked list
	delete secondList;

	return 0;
}