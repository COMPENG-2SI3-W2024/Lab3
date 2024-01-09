#include "ItemBin.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

ItemBin::ItemBin(GameMechs* gm)
{
    gmRef = gm;
    boardRef = gmRef->getBoardRef();  
    //myItem = new objPos(12, 12, 32, 'A', '*');  

        // Added for Lab 3 Validation - this part will speed up the generateItem() process by offloading
        // random prefix / number / symbol generation from runtime to initialization.
        myStack = new objPosStack();
        myStack->populateRandomElements(STACK_SIZE);

    myDrawItem = myStack->top();
    myDrawItem.printObjPos();

    srand(time(NULL));    
}

ItemBin::~ItemBin()
{
        // Added for Lab 3 Validation
        delete myStack;
}

void ItemBin::drawItem()
{   
    int x = myDrawItem.getX();
    int y = myDrawItem.getY();
    char num[2];  // convert number to displayable chars
    DigitToChar(num);

    boardRef[y][x] = myDrawItem.getSym();
    boardRef[y-1][x-1] = myDrawItem.getPF();
    boardRef[y-1][x] = num[0];
    boardRef[y-1][x+1] = num[1];
}

void ItemBin::undrawItem()
{
    int x = myDrawItem.getX();
    int y = myDrawItem.getY();

    if(x == 0 || y == 0) return;

    boardRef[y][x] = ' ';
    boardRef[y-1][x-1] = ' ';
    boardRef[y-1][x] = ' ';
    boardRef[y-1][x+1] = ' ';
}

void ItemBin::DigitToChar(char result[])
{
    int number = myDrawItem.getNum();
    result[0] = (number / 10) + '0';
    result[1] = (number % 10) + '0';
}

// TARGET    
void ItemBin::generateItem()
{
    // Step 1: Get Player Ref from GameMech for Player pos
    Player** plList = gmRef->getPlayerListRef();
    int playerCount = gmRef->getPlayerCount();
    
    int bitVec[gmRef->getBoardSizeX()][gmRef->getBoardSizeY()] = {0};

    objPosList *playerPos;    
    int playerLength;
    objPos target;    

    for(int j = 0; j < playerCount; j++)
    {
        playerPos = plList[j]->getPlayerPos();
        playerLength = playerPos->getSize();
        playerPos->resetReadPos();

        for(int i = 0; i < playerLength; i++)
        {
            target = playerPos->getNext();
            bitVec[target.getX()][target.getY()] = 1;        
        }    
    }

    int randCandidateX = 0;
    int randCandidateY = 0;

    // Lab 3 - pre-generated items follow your own generation trend without
    //  spending time in runtime calculation.
        do
        {
            randCandidateX = rand() % (gmRef->getBoardSizeX() - 4) + 2;
            randCandidateY = rand() % (gmRef->getBoardSizeY() - 4) + 2;
        } while(bitVec[randCandidateX][randCandidateY] != 0);

    cout << "undraw";
    undrawItem();  
    
    myDrawItem = myStack->pop();
    if(myDrawItem.getX() == -99) // end of stack items
    {
        gmRef->setExitFlag();
        return;
    }

    myDrawItem.setX(randCandidateX);
    myDrawItem.setY(randCandidateY);

    drawItem();
    
}

objPos ItemBin::getItem()
{
    return myDrawItem;
}
