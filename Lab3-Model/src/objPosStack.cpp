#include "objPosStack.h"
#include "objPosArrayList.h"
#include "objPosDLinkedList.h"

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

objPosStack::objPosStack()
{
    myList = new objPosDLinkedList();
}

objPosStack::~objPosStack()
{
    delete myList;
}

void objPosStack::populateRandomElements(int size)
{
    srand(time(NULL));    
    generateObjects(size);

    //cout << "Before Sorting" << endl;
    //printMe();

    sortByTenScoreBS(); 
    //sortByTenScoreSS();  
    //sortByTenScoreIS(); 

    //cout << "After Sorting" << endl;
    //printMe();    
}


void objPosStack::generateObjects(int count)
{
    objPos temp(0, 0, 0, 0, 0);
    int randCandidate;

    for(int i = 0; i < count; i++)
    {
        randCandidate = rand() % 26 + 'A';  // 26 alpabets
        if(rand() % 2) randCandidate += 32; // randomly lowercased
        temp.setPF((char)randCandidate);

        // Number [00, 99]
        temp.setNum(rand() % 100);   
        temp.setSym('*');
        push(temp);
    }    
}

int objPosStack::sortByTenScoreBS()
{
    int passes = 0;
    int size = myList->getSize();
    int notdone = 0;  // Non-zero = true, Zero = false;
    
    do{
        notdone = 0;
        
        for(int i = 0; i < size - 1; i++)
        {
            objPos currPos = myList->get(i);
            objPos nextPos = myList->get(i + 1);

            if((currPos.getNum() / 10) < (nextPos.getNum() / 10))
            {
                // SWAP!
                myList->set(nextPos, i);
                myList->set(currPos, i + 1);

                notdone++;
            }
        }

        passes++;

    }while(notdone);

    return passes;
}


void objPosStack::push(const objPos &thisPos) const
{
    objPos temp = thisPos;
    myList->insertTail(thisPos);
}

objPos objPosStack::pop()
{
    if(myList->getSize() <= 0)
    {
        cout << "Stack Underflow!";
        return objPos(-99, 0, 0, 0, 0);
    }
    return myList->removeTail();
}

objPos objPosStack::top()
{
    return myList->getTail();
}

int objPosStack::size()
{
    return myList->getSize();
}

void objPosStack::printMe()
{
    cout << "vv Stack Bottom vv" << endl;
    myList->printList();
    cout << "^^ Stack Top ^^" << endl;
    cout << "Stack Size: " << size() << endl;
}