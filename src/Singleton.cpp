//
//  main.cpp
//  Singleton
//
//  Created by Carlos Adan Cortes De la Fuente on 2018.
//  Copyright © 2018 krlozadan. All rights reserved.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// Template Singleton Class
template <class T>
class Singleton
{
protected:
	static T* mInstance;
	// Private Constructor
	Singleton() {
		cout << "Constructor of Singleton Class Called" << endl;
	};
	// Destructor
	virtual ~Singleton() {
		cout << "Destructor of Singleton Class Called" << endl;
	};

public:
	// Removes the copy constructor
	Singleton(const Singleton&) = delete;
	// Removes the copy assignment operator
	Singleton& operator= (const Singleton) = delete;

	// Lazy instantiation
	static T* GetInstance()
	{
		if (!mInstance)
		{
			cout << "We created the first instance" << endl;
			mInstance = new T();
		}
		return mInstance;
	}
};

class Dog : public Singleton<Dog>
{
public:
	Dog()
	{
		cout << "Dog Constructor Called" << endl;
	}
	~Dog()
	{
		cout << "Dog Destructor Called" << endl;
	}
	void Bark() {
		cout << "Woof Woof" << endl;
	}
};


Dog* Singleton<Dog>::mInstance = nullptr;


int main() {

	// Create two dogs but we only allocate memory once
	Dog* myDog = Dog::GetInstance();
	Dog* myDog2 = Dog::GetInstance();
	// Deletes the static version of dog
	delete myDog;
	// This throws an error because the singleton version of dog doesn't exist anymore
	//delete myDog2; 
	return 0;
}

