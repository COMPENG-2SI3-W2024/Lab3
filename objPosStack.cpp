#include "objPosStack.h"
#include "objPosSHLinkedList.h"

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

// Available Data Members from objPosStack.h (Must Review)
//
//      objPosList* myList
//      
//  This is the polymorphic list pointer to the underlying List data structure to
//   support all Stack functionalities
//
//  You should use the provided objPosSHLinkedList as your main design param (Singly with Header)


objPosStack::objPosStack()
{
    // Constructor   

}


objPosStack::~objPosStack()
{
    // Destructor

}


void objPosStack::populateRandomElements(int size)
{
    // This function generates the number of randomly generated objPos instances with uninitialized
    //  x-y coordinate on the Stack, then sort them in ascending order using the digit of 10
    //  of the **number** field in objPos instances.

    // Implementation done.  You'd have to implement the following two private helper functions above.
    srand(time(NULL));
    generateObjects(size);
    sortByTenScoreBS();   // bubble sort
}




// private helper function
void objPosStack::generateObjects(int count)
{
    // Generate and pushes individual objPos isntances with randomly generated Prefix, Number, and Symbol.
    // The total number of generated instances is capped by input variable **count**.
    
    // 1. Generate Prefix A-Z and a-z.  Alphabetic characters only.
    // 2. Generate Number [0, 99]
    // 3. Leave Symbol as *
    // Push every randomly generately objPos into the Stack.

}


// private helper function
void objPosStack::sortByTenScoreBS()
{
    // Use BUBBLE or SELECTION SORT to sort all the objPos instances in the Stack in ascending order using the doigit of 10
    //  of the **number** field of objPos.

    // You can use the relevant insertion, removal, getter, and setter methods from the objPosSHLinkedList interface
    //  to complete the sorting operations.

    

}




void objPosStack::push(const objPos &thisPos) const
{
    // Push thisPos on to the Stack.

}

objPos objPosStack::pop()
{
    // Pop the top element of the Stack.
    //  If the Stack is empty, return objPos(-99, 0, 0, 0, 0)
    
}

objPos objPosStack::top()
{
    // Return the top element of the Stack without removing it
    //  If the Stack is empty, return objPos(-99, 0, 0, 0, 0)
    
}

int objPosStack::size()
{
    // Return the size of the Stack 
    //  Think about which objPosSHLinkedList method can realize this operation.

}

void objPosStack::printMe()
{
    // NOT GRADED
    //  Print the contents of the Stack

    // IMPORTANT: USE THIS METHOD FOR DEBUGGING!!!
    
}