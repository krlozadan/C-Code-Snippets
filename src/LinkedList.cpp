//
//  LinkedLists.cpp
//  LinkedLists Main Entry Point
//
//  Created by Carlos Adan Cortes De la Fuente 
//  Copyright © 2018 krlozadan. All rights reserved.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template<class T>
class Node
{
public:
	// Members
	T* mData;
	Node* mNext;

	// Constructor
	Node()
	{
		mData = nullptr;
		mNext = nullptr;
	}

	// Overloading constructor only with data
	Node(T* data)
	{
		mData = data;
		mNext = nullptr;
	}

	// Overloading constructor with both properties
	Node(T* data, Node* next)
	{
		mData = data;
		mNext = next;
	}

	// Destructor
	~Node()
	{
		cout << "Deleted Node: " << this << endl;
		mData = nullptr;
		mNext = nullptr;
	}
};

template<class T>
class LinkedList
{
private:
	// Members
	Node<T>* mHead;
	Node<T>* mTail;
	int mSize;

	// Adds the first node to the list
	void AddFirstNode(T* pData)
	{
		// Creates first node and initialize the LinkedList
		Node<T>* newNode = new Node<T>(pData);
		mHead = newNode;
		mTail = newNode;
	}

	// Checks if index is inaccesible
	bool IsIndexAccesible(int index)
	{
		return (index >= 0 && index < mSize);
	}

public:
	// Constructor
	LinkedList()
	{
		mHead = nullptr;
		mTail = nullptr;
		mSize = 0; // Initialize the list to cero elements
	}

	// Destructor
	~LinkedList() 
	{
		if (mSize > 0)
		{
			// Loops through the original size getting rid of every node in the list
			int originalListSize = mSize;
			for (int i = 0; i < originalListSize; i++)
			{
				this->RemoveNodeAt(0);
			}
			mHead = nullptr;
			mTail = nullptr;
		}
	}

	// Adds node at the start of the linked list
	void AddNodeToHead(T* pData)
	{
		// Checks if this is the first object in the structure
		if (mSize == 0)
		{
			AddFirstNode(pData);
		}
		else
		{
			// Starts adding more nodes to the head of the list
			Node<T>* newNode = new Node<T>(pData, mHead);
			mHead = newNode;
		}
		// Adds a number to the size
		mSize++;
	}

	// Adds a node at the end of the linked list
	void AddNodeAtTail(T* pData)
	{
		// Checks if this is the first object in the structure
		if (mSize == 0)
		{
			AddFirstNode(pData);
		}
		else
		{
			Node<T>* newNode = new Node<T>(pData);
			mTail->mNext = newNode;
			mTail = newNode;
		}
		// Adds a number to the size
		mSize++;
	}

	// Returns the head node
	Node<T>* GetHead()
	{
		return mHead;
	}

	// Returns the tail node
	Node<T>* GetTail()
	{
		return mTail;
	}

	// Returns the size of the linked list (number of elements)
	int GetSize()
	{
		return mSize;
	}

	// Returns node at index
	Node<T>* GetNode(int index)
	{
		// Checks if the index is accesible
		if (!IsIndexAccesible(index))
		{
			return nullptr;
		}
		// Checks if the user wants the first node 
		else if (index == 0)
		{
			return mHead;
		}
		// Checks if the user wants the first node 
		else if (index > 0 && index == mSize - 1)
		{
			return mTail;
		}
		// Th euser wants an intermediate object
		else 
		{
			// Loops through the linked list
			Node<T>* node = mHead;
			int i = 0;
			do
			{
				node = node->mNext;
				i++;
			} while (i != index);
			return node;
		}
	}

	//  Remove node at index
	void RemoveNodeAt(int index)
	{
		// Checks if the index is accesible
		if (!IsIndexAccesible(index))
		{
			cout << "Index is not accesible" << endl;
			return;
		}

		// Removes the only node in the linked list
		if (mSize == 1)
		{
			delete mHead;
			mHead = nullptr;
			mTail = nullptr;
		}
		// Converts the two linked list to a single item
		else if (mSize == 2)
		{
			// Checks which node is going to get disposed
			if (index == 0) // Removes Head Node and makes it tail also
			{
				delete mHead;
				mHead = mTail;
			}
			else if(index == 1) // Removes Tail Node and Makes the Head the tail also
			{
				delete mTail;
				mHead->mNext = nullptr;
				mTail = mHead;
			}
		}
		else // There is more than 2 nodes in the list
		{
			// Deletes the head node
			if (index == 0)
			{
				Node<T>* oldHead = mHead;
				mHead = oldHead->mNext;
				delete oldHead;
			}
			// Deletes the tail
			else if (index == mSize - 1)
			{
				// Loops through the list to get the node thats pointing to the tail
				Node<T>* currentNode = mHead;
				for (int i = 1; i < mSize - 1; i++)
				{
					currentNode = currentNode->mNext;
				}
				// Changes the tail node
				delete mTail;
				currentNode->mNext = nullptr;
				mTail = currentNode;
			}
			// Deletes any node inbetween
			else
			{
				// Loops through the list to get the wanted node 
				Node<T>* currentNode = mHead;
				Node<T>* nextNode = mHead->mNext;
				for (int i = 1; i < mSize; i++)
				{
					if (i == index)
					{
						currentNode->mNext = nextNode->mNext;
						delete nextNode;
						break;
					}
					else
					{
						currentNode = currentNode->mNext;
						nextNode = currentNode->mNext;
					}
				}
			}
		}
		// Reduces the size of the list
		mSize--;
	}

	// find and remove node return value is if removed or not
	bool RemoveNode(T* pData)
	{
		// Checks if the list is empty
		if (mSize == 0)
		{
			cout << "List is empty" << endl;
			return false;
		}
		else
		{
			bool foundNode = false;
			// Loops through the linked list to find the data
			Node<T>* currentNode = mHead;
			for (int i = 0; i < mSize; i++)
			{
				if (currentNode->mData == pData)
				{
					cout << "This one is going out " << currentNode << endl;
					RemoveNodeAt(i);
					foundNode = true;
					break;
				}
				else
				{
					currentNode = currentNode->mNext;
				}	
			}
			return foundNode;
		}
	}
	
	// Returns a new list with same nodes
	LinkedList* Clone()
	{
		LinkedList<T>* newList = new LinkedList();
		// Checks if the list is not empty
		if (mSize > 0)
		{
			Node<T>* currentNode = mHead;
			for (int i = 0; i < mSize; i++)
			{
				// Adds the new nodes to the list
				newList->AddNodeAtTail(currentNode->mData);
				currentNode = currentNode->mNext;
			}
		}
		newList->mSize = mSize;
		return newList;
	}
};

int main() {
	// Dummy Data
	int data1 = 1;
	int data2 = 2;
	int data3 = 3;
	int data4 = 4;
	int data5 = 5;
	int data6 = 6; // Used just for fonal copy of list

	// Integer Linked list example
	LinkedList<int> myLinkedList;

	// Adding nodes to the head and at tail of linked list
	myLinkedList.AddNodeToHead(&data1);
	myLinkedList.AddNodeToHead(&data2);
	myLinkedList.AddNodeAtTail(&data3);
	myLinkedList.AddNodeToHead(&data4);
	myLinkedList.AddNodeAtTail(&data5);

	// getting the head or tail node directly
	Node<int>* headNode = myLinkedList.GetHead();
	Node<int>* tailNode = myLinkedList.GetTail();
	
	// Getting the size of the linked list
	int listSize = myLinkedList.GetSize();

	// Different cases for the node at index
	// TRY EACH ONE
	/*Node<int>* nodeAtIndexHead = myLinkedList.GetNode(0);
	Node<int>* nodeAtIndexTail = myLinkedList.GetNode(4);
	Node<int>* nodeAtIndexNull = myLinkedList.GetNode(5);
	Node<int>* nodeAtIndexMiddle = myLinkedList.GetNode(2);*/

	// Testing the deletion of the nodes
	// TRY EACH ONE
	/*myLinkedList.RemoveNodeAt(2);
	myLinkedList.RemoveNodeAt(8);
	bool removed = myLinkedList.RemoveNode(&data3);
	bool removed2 = myLinkedList.RemoveNode(&data6);*/

	// Copy the linked list
	LinkedList<int>* newList = myLinkedList.Clone();
	newList->AddNodeAtTail(&data6);

	// Deletes the copied list
	delete newList;

	return 0;
}