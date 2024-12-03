#include "Player.h"
using namespace std; 

Player::Player(GameMechs *thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myFSMMode = STOP;

    // more actions to be included
    
    
    playerPosList = new objPosArrayList();

    objPos initialPos = {mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2 , '@'};
    playerPosList->insertHead(initialPos);
    
}

Player::~Player()
{
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list --> update to return
    return playerPosList;
    //return playerPos;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    char input = mainGameMechsRef->getInput();
    
    if(input != 0)
    {
        switch (input)
        {
            
            case 'W':
            case 'w':
        
                if (myFSMMode != DOWN && myFSMMode != UP)
                {
                    myFSMMode = UP;
                }
                break;
        

            case 'S':
            case 's':

            
                if (myFSMMode != UP && myFSMMode != DOWN)
                {
                    myFSMMode = DOWN;
                }
                break;
            

            case 'A':
            case 'a':
            
                if (myFSMMode != RIGHT && myFSMMode != LEFT)
                {
                    myFSMMode = LEFT;
                }
                break;
            

            case 'D':
            case 'd':
            
                if (myFSMMode != LEFT && myFSMMode != RIGHT)
                {
                    myFSMMode = RIGHT;
                }
                break;
            
        }
    }

    mainGameMechsRef->clearInput();
    
}

void Player::movePlayer()
{
    objPos currentHead;
    currentHead = getPlayerPos()->getHeadElement();

    int newX = currentHead.pos->x;
    int newY = currentHead.pos->y;

    // PPA3 Finite State Machine logic
    if(myFSMMode != STOP)
    {  

        int height = mainGameMechsRef->getBoardSizeY();
        int width = mainGameMechsRef->getBoardSizeX();

        switch (myFSMMode)
        {
            case LEFT:
                if(newX > 1)
                {
                    currentHead.pos->x --;
                }
                else
                {
                    currentHead.pos->x = width - 2;
                }                
                break;

            case RIGHT:
                if(newX < width - 2)
                {
                    currentHead.pos->x ++;
                }
                else
                {
                    currentHead.pos->x = 1;
                }
                break;

            case UP:
                if(newY > 1)
                {
                    currentHead.pos->y --;
                }
                else
                {
                    currentHead.pos->y = height - 2;
                }
                break;

            case DOWN:
                if(newY < height-2)
                {
                    currentHead.pos->y ++;
                }
                else
                {
                    currentHead.pos->y = 1;
                }
                break;
            }
    }

    //currentHead.setObjPos(playerPosList->getHeadElement().pos->x, playerPosList->getHeadElement().pos->y, currentHead.getSymbol());
    getPlayerPos()->insertHead(currentHead);
    if (checkSelfCollision())
    {
        if(checkFoodConsumption())
        {
            increasePlayerLength();
        }
        else
        {
            getPlayerPos()->removeTail();
        }
    }

}
// More methods to be added

bool Player::checkFoodConsumption()
{
    objPos snakeHead = getPlayerPos()->getHeadElement();
    objPos foodYum = mainGameMechsRef->getFoodPos();

    if(snakeHead.pos->x == foodYum.pos->x && snakeHead.pos->y == foodYum.pos->y)
    {
        return true; //checking to see if food was eaten 
    }

    return false;
}


void Player::increasePlayerLength()
{
    mainGameMechsRef->generateFood(getPlayerPos());
    mainGameMechsRef->incrementScore();
}


bool Player::checkSelfCollision()
{
    objPos head = getPlayerPos()->getHeadElement();

    for(int i = 1; i<getPlayerPos()->getSize(); i++)
    {
        if(head.pos->x == getPlayerPos()->getElement(i).pos->x && head.pos->y == getPlayerPos()->getElement(i).pos->y)
        {
            return true; //collsion occured 
        }
    }

    return false; //no collision 
}