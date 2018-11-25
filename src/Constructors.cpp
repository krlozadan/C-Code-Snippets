//
//  main.cpp
//  Constructors
//
//  Created by Carlos Adan Cortes De la Fuente on 30/01/18.
//  Copyright © 2018 krlozadan. All rights reserved.
//

#include <iostream>

using namespace std;

class MyClass1
{
public:
    int x;
    int y;
    int z;
};

// EXECISE ONE
// Copy of MyClass1 but with Constructor, Destructor, Copy Constructor and Assignment Operator Defined
class MyClass2
{
public:
    // Members
    int x;
    int y;
    int z;
    
    // Constructor & Destructor
    MyClass2(){}
    ~MyClass2(){}
    
    // Copy Constructor
    MyClass2 (const MyClass2 &obj){
        // Copies the values of the first instance
        x = obj.x;
        y = obj.y;
        z = obj.z;
    }
    
    // Assignment Operator
    MyClass2& operator=(const MyClass2& obj)
    {
        // Check if the object being passed is not exactly the same object to the one we are comparing
        if(this != &obj)
        {
            x = obj.x;
            y = obj.y;
            z = obj.z;
        }
        return *this;
    }
};

// EXECISE TWO
// Constructor with argument list and initializer
class MyClass3
{
private:
    // Members
    int x;
    int y;
    int z;
    
public:
    // Forbidden Default Constructor
    MyClass3() = delete;
    // Deconstructor
    ~MyClass3(){}
    // Constructor with initializer list
    MyClass3(int numX, int numY, int numZ) : x(numX), y(numY), z(numZ) {}
    // Forbidden Copy Constructor
    MyClass3(const MyClass3& obj) = delete;
};

// EXECISE THREE
// 1. Duplicate "MyClass1" and call it "MyClass4" and add a constructor and destructor
class MyClass4
{
public:
    // Members
    int x;
    int y;
    int z;
    // Constructor and deconstructor
    MyClass4(){}
    ~MyClass4(){}
};
// 2. Make another class called "MyClass5" that inherits from "MyClass4"
// 3. Add a constructor and destructor to "MyClass5"
class MyClass5 : MyClass4
{
public:
    // Constructor and deconstroctor
    MyClass5(){}
    ~MyClass5(){}
};


// EXECISE ONE
// 1. Creates a variable "myClassA" of type "MyClass2"
// 2. Creates a variable "myClassB" of type "MyClass2" using the copy constructor
// 3. Assign "myClassA" to "myClassB"
// 4. Outputs both objects to the console
void MyClass2Usage()
{
    // Creates and copy construct class A to B
    MyClass2 myClassA;
    myClassA.x = 10;
    myClassA.y = 20;
    myClassA.z = 30;
    MyClass2 myClassB(myClassA);
    // Outputs the variables to check they are the same
    cout << "My Class A values: " << myClassA.x << " " << myClassA.y << " " << myClassA.z << endl;
    cout << "My Class B values: " << myClassB.x << " " << myClassB.y << " " << myClassB.z << endl;
    
    // Asks the user to change the values from class A to asign to class B
    cin >> myClassA.x;
    cin >> myClassA.y;
    cin >> myClassA.z;
    myClassB = myClassA;
    // Outputs the variables to check they are the same
    cout << "My Class A values: " << myClassA.x << " " << myClassA.y << " " << myClassA.z << endl;
    cout << "My Class B values: " << myClassB.x << " " << myClassB.y << " " << myClassB.z << endl;
}

int main() {
    
    // EXECISE ONE
    MyClass2Usage();
    
    // EXECISE TWO
    // MyClass3 test1
    MyClass3 test2(1,2,3);
    // MyClass3 test3(3);
    // Only the uncommented code would compile
    
    // EXECISE THREE
    MyClass4 class4;
    MyClass5 class5;
    
    return 0;
}
