// DogPointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


class Dog
{

private:
	// Counts the number of noises
	int mNoises;
    
public:
	// Constructor
	Dog() 
    {
        // Initialize number of noises
        mNoises = 0;
        std::cout << "Dog instance created" << std::endl;
    }

    // Destructor
	~Dog()
    {
        std::cout << "Dog instance destroyed" << std::endl;
    }

	// Increments the number of noises made by the dog
	void Woof()
    {
        ++mNoises;
    }

	// Returns an instance of "Dog" using dynamically allocated memory
	Dog* CreateDog()
    {
        Dog* newDog = new Dog();
	    return newDog;
    }

	// Makes the dog bark three times
	void BarkThreeTimes()
    {
        // Creates a new d
        Dog* newDog = Dog::CreateDog();
        
        // Makes the instance bark three times
        for (int i = 0; i < 3; i++)
        {
            newDog->Woof();
        }
        // Frees the allocated memory
        delete newDog;
    }

	// Makes each dog bark once
	void ThreeDogsBark2(Dog* dog1, Dog* dog2, Dog* dog3)
    {
        dog1->Woof();
        dog2->Woof();
        dog3->Woof();
    }

	// Creates three dogs using "CreateDog" and then passes them to "ThreeDogsBark2"
	void ThreeDogsBark1()
    {
        // Creates 3 new dog pointer variables
        Dog* dog1 = Dog::CreateDog();
        Dog* dog2 = Dog::CreateDog();
        Dog* dog3 = Dog::CreateDog();

        // Makes the newly created dogs to bark
        Dog::ThreeDogsBark2(dog1, dog2, dog3);

        // Clean the memory allocated by the three newly created dogs
        delete dog1;
        delete dog2;
        delete dog3;
    }

	// Creates three "Dog" instances on the stack and then passes them to "ThreeDogsBark2"
	void ThreeDogsBarkStack()
    {
        // Creates 3 instances of Dog in the stack
        Dog dog1;
        Dog dog2;
        Dog dog3;
        // make the 3 dogs bark once
        Dog::ThreeDogsBark2(&dog1, &dog2, &dog3);
    }

};


int main()
{
    
	// Create a dog instance on the stack
	Dog myDog;

	// Exercise 1
	Dog* e1Dog = myDog.CreateDog();
	delete e1Dog;

	// Exercise 2
	myDog.BarkThreeTimes();

	// Exercise 3
	// 1.
	Dog* e3Dog1 = myDog.CreateDog();
	Dog* e3Dog2 = myDog.CreateDog();
	Dog* e3Dog3 = myDog.CreateDog();
	myDog.ThreeDogsBark2(e3Dog1, e3Dog2, e3Dog3);
	delete e3Dog1;
	delete e3Dog2;
	delete e3Dog3;

	// 2.
	myDog.ThreeDogsBark1();

	// Exercise 4
	myDog.ThreeDogsBarkStack();  
	
	return 0;
}

