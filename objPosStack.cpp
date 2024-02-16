#include "objPosStack.h"
#include "objPosDLinkedList.h"

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
//  You should use objPosDLinkedList as your main design param


objPosStack::objPosStack()
{
    // Constructor
    //   Instantiate myList as objPosDLinkedList.  You may use objPosArrayList for testing purpose only.
}


objPosStack::~objPosStack()
{
    // Destructor
    //  Just delete myList (and all otherheap members, if any)
}


// private helper function
void objPosStack::generateObjects(int count)
{
    // Generate and pushes individual objPos isntances with randomly generated Prefix, Number, and Symbol.
    // The total number of generated instances is capped by input variable **count**.
}


// private helper function
int objPosStack::sortByTenScoreBS()
{
    // Use BUBBLE SORT to sort all the objPos instances in the Stack in ascending order using teh doigit of 10
    //  of the **number** field of objPos.

    // You can use the relevant insertion and removal methods from the objPosDLinkedList interface
    //  to complete the sorting operations.
}


void objPosStack::populateRandomElements(int size)
{
    // This function generates the number of randomly generated objPos instances with uninitialized
    //  x-y coordinate on the Stack, then sort them in ascending order using the digit of 10
    //  of the **number** field in objPos instances.

    // Implementation done.  You'd have to implement the following two private helper functions above.
    generateObjects(size);
    sortByTenScoreBS();
}



void objPosStack::push(const objPos &thisPos) const
{
    // Push thisPos on to the Stack.
    //  Think about which objPosDLinkedList method can realize this operation.
}

objPos objPosStack::pop()
{
    // Pop the top element of the Stack.
    //  Think about which objPosDLinkedList method can realize this operation.
}

objPos objPosStack::top()
{
    // Return the top element of the Stack without removing it
    //  Think about which objPosDLinkedList method can realize this operation.
}

int objPosStack::size()
{
    // Return the size of the Stack 
    //  Think about which objPosDLinkedList method can realize this operation.
}

void objPosStack::printMe()
{
    // NOT GRADED
    //  Print the contents of the Stack
    //  Think about which objPosDLinkedList method can partially realize this operation.

    // IMPORTANT: USE THIS METHOD FOR DEBUGGING!!!
}