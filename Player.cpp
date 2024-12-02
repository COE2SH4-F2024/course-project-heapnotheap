#include "Player.h"

Player::Player(GameMechs *thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myFSMMode = STOP;

    // more actions to be included
    
    
    playerPosList = new objPosArrayList();

    objPos initialPos = {mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2 , '@'};
    playerPosList->insertHead(initialPos);
    
    //playerPos.pos->x = mainGameMechsRef->getBoardSizeX() / 2;
    //playerPos.pos->y = mainGameMechsRef->getBoardSizeY() / 2;
    //playerPos.symbol = '@';
    
}

Player::~Player()
{
    // delete any heap members here
    // no keywords in the __cpp_delegating_constructor
    // leave the destructor empty for NOW
    // delete[]
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list --> update to return
    return playerPosList->getHeadElement();
    //return playerPos;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    char input = mainGameMechsRef->getInput();
    
    switch (input)
    {
        
    case 'W':
    case 'w':
    {
        if (myFSMMode == LEFT || myFSMMode == RIGHT)
        {
            myFSMMode = UP;
        }
        break;
    }

    case 'S':
    case 's':

    {
        if (myFSMMode == LEFT || myFSMMode == RIGHT)
        {
            myFSMMode = DOWN;
        }
        break;
    }

    case 'A':
    case 'a':
    {
        if (myFSMMode == UP || myFSMMode == DOWN)
        {
            myFSMMode = RIGHT;
        }
        break;
    }

    case 'D':
    case 'd':
    {
        if (myFSMMode == UP || myFSMMode == DOWN)
        {
            myFSMMode = LEFT;
        }
        break;
    }
    }
}

void Player::movePlayer()
{
    objPos currentHead;
    currentHead = playerPosList->getHeadElement();

    int newX = currentHead.pos->x;
    int newY = currentHead.pos->y;

    // PPA3 Finite State Machine logic
    switch (myFSMMode)
    {
    case LEFT:
        //playerPos.pos->x++;
        playerPosList->getHeadElement().pos->x++;
        //newX.x++;
        //playerPosList->getHeadElement();
        playerPosList->removeTail();
        
        break;

    case RIGHT:
        //playerPos.pos->x--;
        playerPosList->getHeadElement().pos->x--;
        /*
        playerPosList->getHeadElement();
        
        */
       playerPosList->removeTail();
        break;

    case UP:
        playerPosList->getHeadElement().pos->y--;
        /*
        playerPosList->getHeadElement();
        
        */
        playerPosList->removeTail();
        break;

    case DOWN:
        //playerPos.pos->y++;
        playerPosList->getHeadElement().pos->y++;
        //playerPosList->getHeadElement();
        playerPosList->removeTail();
        
        break;

    case STOP:
        return;
    default:
        return;
    }

    if (playerPosList->getHeadElement().pos->x >= mainGameMechsRef->getBoardSizeX()) // wrap-around
    {
        playerPosList->getHeadElement().pos->x = 2;
    }
    else if (playerPos.pos->x <= 1)
    {
        playerPosList->getHeadElement().pos->x = 18;
    }

    else if (playerPosList->getHeadElement().pos->y >= mainGameMechsRef->getBoardSizeY())
    {
        playerPosList->getHeadElement().pos->y = 2;
    }
    else if (playerPos.pos->y == 1)
    {
        playerPosList->getHeadElement().pos->y = 8;
    }

    currentHead.setObjPos(playerPosList->getHeadElement().pos->x, playerPosList->getHeadElement().pos->y, currentHead.getSymbol());
    playerPosList ->insertHead(currentHead);

}

// More methods to be added