#include "cmdQueue.h"

#include <iostream>
using namespace std;

// Available Data Members from cmdQueue.h

// You must implement the array-based circular queue as discussed in class

// You must NOT use any existing data structures such as Lists to design the queue.


cmdQueue::cmdQueue()
{
    // Constructor

}

cmdQueue::cmdQueue(int cap)
{
    // Additional Constructor
}

cmdQueue::~cmdQueue()
{
    // Destructor 
    
}

void cmdQueue::enqueue(char thisCmd)
{
    // Enqueue into Circular Queue

}

char cmdQueue::dequeue()
{
    // Dequeue from Circular Queue
}

int cmdQueue::getSize() const
{
    // Return the size of the Queue
    
}

void cmdQueue::clearQueue()
{
    // Remove all elements from the Queue

}

void cmdQueue::printMe() const
{
    // NOT GRADED
    //  Print the contents of the Queue
    
    // IMPORTANT: USE THIS METHOD FOR DEBUGGING!!!
}