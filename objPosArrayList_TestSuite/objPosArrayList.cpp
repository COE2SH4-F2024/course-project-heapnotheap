#include "objPosArrayList.h"
#include <iostream>

#include "MacUILib.h"
using namespace std; 

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    listSize = 0; //initialy set to 0
    arrayCapacity = ARRAY_MAX_CAP; // array size is 200 
    // allocate memory on the heap for an int-array
    aList = new int[ARRAY_MAX_CAP];
    cout <<"Default Constructor Called"<< endl;
}

objPosArrayList::~objPosArrayList()
{
    cout <<"Destructor Called"<< endl;
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    return aList[0] = thisPos;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    
}

void objPosArrayList::removeHead()
{
    
}

void objPosArrayList::removeTail()
{
    
}

objPos objPosArrayList::getHeadElement() const
{
    
}

objPos objPosArrayList::getTailElement() const
{
    
}

objPos objPosArrayList::getElement(int index) const
{
    
}