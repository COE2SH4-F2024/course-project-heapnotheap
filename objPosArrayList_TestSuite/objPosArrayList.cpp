#include "objPosArrayList.h" //copy some header files
#include <iostream>

#include "MacUILib.h"
using namespace std; //using names form the standard library

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    // <<"Default Constructor Called"<< 
    listSize = 0; //initialy set to 0
    arrayCapacity = ARRAY_MAX_CAP; // array size is 200 
    // allocate memory on the heap for an int-array
    //create a 200 int array on the heap
    aList = new objPos[ARRAY_MAX_CAP]; // the new thing being made has to have the same type objPos*

}

objPosArrayList::objPosArrayList(const objPosArrayList &m ) //creating a new object, incase an object is passed by value 
{
    //<< "Copy Constructor called." <<
    listSize = m.listSize;
    arrayCapacity = m.arrayCapacity;
    aList = new objPos[ARRAY_MAX_CAP]; 
}

objPosArrayList & objPosArrayList::operator=(const objPosArrayList &m ) 
{
    //<< "Copy Assignment Constructor called." <<
    // 'this' is to a pointer reffering to the current object
    if (this != &m) 
    {
        this->listSize = m.listSize;
        this->arrayCapacity = m.arrayCapacity;
        aList = new objPos[ARRAY_MAX_CAP]; 
    }
}

objPosArrayList::~objPosArrayList()
{
    //cout <<"Destructor Called"<< endl;
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    //check if the the array is full
    if (listSize == arrayCapacity)
    {
        return;
    }
    for (int i = listSize; i>0; i--)
    {
        aList[i] = aList[i-1];
    }
    aList[0] = thisPos;
    listSize++; //increment the size of the List by one
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize == arrayCapacity)
    {
        return;
    }
    // no shifting necessary 
    aList[listSize++] = thisPos;
    
}

void objPosArrayList::removeHead()
{
    if (listSize == 0)
    {
        return;
    }
    for (int i = 0; i< listSize-1; i++)
    {
        aList[i] = aList[i+1];
    }
    
    listSize--;
}

void objPosArrayList::removeTail()
{
    if (listSize ==0) //list is empty
    {
        return;
    }
    listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index) const
{
    if(index<0 || index >= listSize)
    {
        return;
    }
    return aList[index];
}