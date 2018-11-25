// BinaryTree.cpp : Defines the entry point for the console application.
//  BinaryTree
//
//  Created by Carlos Adan Cortes De la Fuente.
//  Copyright © 2018 krlozadan. All rights reserved.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <memory> // Smart Pointers
using namespace std;

// Node Template Class
template <class T>
class Node
{
public:

	// Members
	T mData;
	shared_ptr<Node<T>> mLeft;
	shared_ptr<Node<T>> mRight;

	// Constructor
	Node(T data)
	{
		mData = data;
		cout << "New Node Created: " << mData << endl;
	};

	// Destructor
	~Node()
	{
		cout << "Node Deleted: " << mData << endl;
	}
};

// Binary Tree Template Class
template <class T>
class BinaryTree
{
public:
	// Members
	shared_ptr<Node<T>> mRoot;

	// Constructor
	BinaryTree()
	{
		cout << "New Binary Tree Created" << endl;
	};
	// Destructor
	~BinaryTree()
	{
		cout << "Binary Tree Deleted" << endl;
	};

	// Add an item to the tree
	void AddItem(T data)
	{
		// Creates a new node to be added to the tree
		shared_ptr<Node<T>> newNode = make_shared<Node<T>>(data);

		// Creates the root of the binary tree
		if (!mRoot)
		{
			cout << "Added node " << newNode->mData << " to the root" << endl;
			mRoot = newNode;
		}
		// Put it in one of the child
		else
		{
			// Variable to keep track of last parent
			shared_ptr<Node<T>> parentNode = mRoot;
			// Loop until new node is added
			while (true)
			{
				// Decides which side to go to (Left / Right)
				if (newNode->mData < parentNode->mData)
				{
					// If there is no node there, it gets added
					if (!parentNode->mLeft)
					{
						cout << "Added node " << newNode->mData << " to the left of " << parentNode->mData << endl;
						parentNode->mLeft = newNode;
						break;
					}
					else
					{
						// Lets it continue traversing the tree until it finds a place to put the new node
						parentNode = parentNode->mLeft;
						continue;
					}
				}
				else if (newNode->mData > parentNode->mData)
				{
					// If there is no node there, it gets added
					if (!parentNode->mRight)
					{
						cout << "Added node " << newNode->mData << " to the right of " << parentNode->mData << endl;
						parentNode->mRight = newNode;
						break;
					}
					else
					{
						// Lets it continue traversing the tree until it finds a place to put the new node
						parentNode = parentNode->mRight;
						continue;
					}
				}
			}
		}
	}

	// Remove a specific item from the tree
    // TODO: Solve deleting children nodes
	void RemoveItem(T data)
	{
		if (data == mRoot->mData)
		{
			mRoot = nullptr;
			return;
		}

		// Variable to keep track of current node
		shared_ptr<Node<T>> currentNode = mRoot;
		// Loops until it finds the correct node and deletes it
		while(true)
		{
			if(currentNode->mLeft->mData == data)
			{
				// Delete Left Node
				currentNode->mLeft = nullptr;
				break;
			}
			else if (currentNode->mRight->mData == data)
			{
				// Delete right Node
				currentNode->mRight = nullptr;
				break;
			}
			// Decides which side to go to (Left / Right)
			else if (data < currentNode->mData)
			{
				currentNode = currentNode->mLeft;
			}
			else if (data > currentNode->mData)
			{
				currentNode = currentNode->mRight;
			}
		}
	}

	// Prints Tree Values using In-Order Traversing (Recursive)
	void InOrderTraverse(shared_ptr<Node<T>> node)
	{
		// Checks if the node exists
		if (!node)
		{
			return;
		}		
		// Go to left child 
		InOrderTraverse(node->mLeft);
		// Print Node's data
		cout << "In Order: " << node->mData << endl;
		// Go to right child
		InOrderTraverse(node->mRight);
	}

	// Prints Tree Values using Pre-Order Traversing
	void PreOrderTraverse(shared_ptr<Node<T>> node)
	{
		// Checks if the node exists
		if (!node)
		{
			return;
		}

		// Print Node's data
		cout << "Pre Order: " << node->mData << endl;
		// Go to left child 
		PreOrderTraverse(node->mLeft);
		// Go to right child 
		PreOrderTraverse(node->mRight);
	}

	// Prints Tree Values using Post-Order Traversing
	void PostOrderTraverse(shared_ptr<Node<T>> node)
	{
		// Checks if the node exists
		if (!node)
		{
			return;
		}

		// Go to left child 
		PostOrderTraverse(node->mLeft);
		// Go to right child 
		PostOrderTraverse(node->mRight);
		// Print Node's data
		cout << "Post Order: " << node->mData << endl;
	}
};

int main()
{
	// Created with unique pointer because it is the only tree
	unique_ptr<BinaryTree<int>> myTree = make_unique<BinaryTree<int>>();

	// Adding nodes to the tree
	myTree->AddItem(10);
	myTree->AddItem(2);
	myTree->AddItem(15);
	myTree->AddItem(4);
	myTree->AddItem(11);
	myTree->AddItem(3);
	myTree->AddItem(7);
	myTree->AddItem(1);
	myTree->AddItem(20);
	myTree->AddItem(14);
	myTree->AddItem(25);
	myTree->AddItem(30);
	myTree->AddItem(18);

	// In Order Traversing
	myTree->InOrderTraverse(myTree->mRoot);

	// Pre order Traversing
	myTree->PreOrderTraverse(myTree->mRoot);

	// Post order Traversing
	myTree->PostOrderTraverse(myTree->mRoot);

	// Removing items from the tree
	myTree->RemoveItem(10);
	//myTree->RemoveItem(10);

	// Prints again to check if the nodes we correclty deleted
	myTree->InOrderTraverse(myTree->mRoot);

	return 0;
}