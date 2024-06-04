#include "cmdQueue.h"

#include <iostream>
using namespace std;

// Available Data Members from objPosStack.h (Must Review)
//
//      DLinkedList<char>* myQueue
//      
//  This is the character-type template Doubly Linked List class to support
//   all the character command Queue operations
//
//  You should also review the DLinkedList<> template class (identical to the lecture examples)


cmdQueue::cmdQueue()
{
    // Constructor
    //  Instantiate myQueue as DLinkedList<char> type to support the queue implementations
<<<<<<< HEAD
    myQueue = new DLinkedList<char>();
=======
>>>>>>> 8bbc28afdf8e09589e8470b935d699b72be9e7bd
}

cmdQueue::~cmdQueue()
{
    // Destructor 
    //  Destroy myQueue on the heap (and also for all other heap members, if any)
<<<<<<< HEAD
    delete myQueue;
=======
>>>>>>> 8bbc28afdf8e09589e8470b935d699b72be9e7bd
}

void cmdQueue::enqueue(char thisCmd)
{
    // Enqueue thisCmd into the Queue
    //  Think about what underlying DLinkedList method can support this operation
<<<<<<< HEAD
    myQueue->addFirst(thisCmd);
=======
>>>>>>> 8bbc28afdf8e09589e8470b935d699b72be9e7bd
}

char cmdQueue::dequeue()
{
    // Dequeue the oldest character command from the queue and return
<<<<<<< HEAD
    //  Think about what underlying DLinkedList method can support this operation
    
    // If no more commands to dequeue, return NULL character ('\0')
    return myQueue->removeLast();
=======
    // If no more commands to dequeue, return NULL character ('\0')
    //  Think about what underlying DLinkedList method can support this operation    
>>>>>>> 8bbc28afdf8e09589e8470b935d699b72be9e7bd
}

int cmdQueue::getSize()
{
    // Return the size of the Queue
    //  Think about what underlying DLinkedList method can support this operation
<<<<<<< HEAD
    return myQueue->getSize();
=======
>>>>>>> 8bbc28afdf8e09589e8470b935d699b72be9e7bd
}

void cmdQueue::clearQueue()
{
    // Clear all tbe elements in the queue
    //  Think about what underlying DLinkedList method can support this operation
<<<<<<< HEAD
    myQueue->makeEmpty();
=======
>>>>>>> 8bbc28afdf8e09589e8470b935d699b72be9e7bd
}

void cmdQueue::printMe()
{
    // NOT GRADED
    //  Print the contents of the Queue
    //  Think about which DLinkedList method can partially realize this operation.
<<<<<<< HEAD

    // IMPORTANT: USE THIS METHOD FOR DEBUGGING!!!
    cout << "Command Queue Contains:" << endl;
    myQueue->printList();
    cout << "Command Queue Size:" << myQueue->getSize() << endl;
=======
>>>>>>> 8bbc28afdf8e09589e8470b935d699b72be9e7bd

    // IMPORTANT: USE THIS METHOD FOR DEBUGGING!!!
}