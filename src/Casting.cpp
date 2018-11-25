//
//  Casting.cpp : Defines the entry point for the console application.
//  Created by Carlos Adan Cortes De la Fuente on 05/03/18.
//  Copyright © 2018 krlozadan. All rights reserved.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//
// example classes you can use in the exercises below:
//

class Animal
{
public:
	Animal()
	{
		cout << "Animal Created" << endl;
	}
	virtual ~Animal()
	{
		cout << "Animal Destroyed" << endl;
	}
};

class Mammal : public Animal
{
public:
	Mammal()
	{
		cout << "Mammal Created" << endl;
	}
	virtual ~Mammal()
	{
		cout << "Mammal Destroyed" << endl;
	}
};

class Human : public Mammal
{
public:
	int age;
	Human()
	{
		age = 0;
		cout << "Human Created" << endl;
	}
	~Human()
	{
		cout << "Human Destroyed" << endl;
	}
};

class Food
{
public:
	Food()
	{
		cout << "Food Created" << endl;
	}
	virtual ~Food()
	{
		cout << "Food Destroyed" << endl;
	}
};

class Savoury : public Food
{
public:
	Savoury()
	{
		cout << "Savoury Created" << endl;
	}
	~Savoury()
	{
		cout << "Savoury Destroyed" << endl;
	}
};

class Dessert : public Food
{
public:
	Dessert()
	{
		cout << "Dessert Created" << endl;
	}
	virtual ~Dessert()
	{
		cout << "Dessert Destroyed" << endl;
	}
};

class Cake : public Dessert
{
public:
	Cake()
	{
		cout << "Cake Created" << endl;
	}
	~Cake()
	{
		cout << "Cake Destroyed" << endl;
	}
};

//
// EXECISE ONE
//

//
// show an example of an implicit type conversion
//

void ImplicitTypeConversion()
{
	// Done with stack and heap variables
	Cake myCake = Cake();
	Food myFood = myCake;

	Food* myFoodPtr = new Cake();
	delete myFoodPtr;
}

//
// EXECISE TWO
//

//
// show an example of a C style cast
//

void CStyleCast()
{
	// Done with stack and heap variables
	Human myHuman = Human();
	Animal myAnimal = (Animal)myHuman;

	Animal* myAnimalPtr = (Animal*) new Human();
	delete myAnimalPtr;
}

//
// EXECISE THREE
//

//
// show an example of a static_cast
//

void StaticCast()
{
	// Upcast
	Animal* myAnimalPtrUpcast = static_cast<Animal*>(new Human());
	delete myAnimalPtrUpcast;

	// Downcast
	Human* myHumanPtrDowncast = static_cast<Human*>(new Animal());
	delete myHumanPtrDowncast;
}

//
// EXECISE FOUR
//

//
// show an example of when a dynamic_cast succeeds
// show an example of when a dynamic_cast fails
//

void DynamicCast()
{
	// Upcast
	Animal* myAnimalPtrUpcast = dynamic_cast<Animal*>(new Human());
	delete myAnimalPtrUpcast;

	// Downcast (This is null)
	Human* myHumanPtrDowncast = dynamic_cast<Human*>(new Animal());

	// Checks at runtime if the human pointer is pointing to a human object indeed
	if (!myHumanPtrDowncast)
	{
		cout << "Human Pointer Downcast is null" << endl;
	}
	else
	{
		delete myHumanPtrDowncast;
	}
}

//
// EXECISE FIVE
//

//
// show an example of a const_cast
//

void ConstCast()
{
	// This prevents from changing any values inside the object
	const Human* notModifiableObject = new Human();
	// Makes the constness to go away
	Human* modifiableObject = const_cast<Human*>(notModifiableObject);

	// This is not allowed!!
	// notModifiableObject->age = 10;

	// This is allowed now...
	modifiableObject->age = 10;

	// Just need to delete once because they are pointing to the same object
	delete notModifiableObject;
}

int main()
{
	ImplicitTypeConversion();
	CStyleCast();
	StaticCast();
	DynamicCast();
	ConstCast();

	return 0;
}