#include "Player.h"

Player::Player(GameMechs *thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myFSMMode = STOP;

    // more actions to be included
    playerPosList = new objPosArrayList();

    objPos initialPos = {mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2 , '@'};

    
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX() / 2;
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY() / 2;
    playerPos.symbol = '@';
    
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
    
    // PPA3 Finite State Machine logic
    switch (myFSMMode)
    {
    case LEFT:
        //playerPos.pos->x++;
        playerPosList->getHeadElement().x++;
        playerPosList->getHeadElement();
        playerPosList->removeTail();
        break;

    case RIGHT:
        playerPos.pos->x--;
        playerPosList->getHeadElement();
        playerPosList->removeTail();
        break;

    case UP:
        playerPos.pos->y--;
        playerPosList->getHeadElement();
        playerPosList->removeTail();
        break;

    case DOWN:
        playerPos.pos->y++;
        playerPosList->getHeadElement();
        playerPosList->removeTail();
        break;
    }

    if (playerPos.pos->x >= mainGameMechsRef->getBoardSizeX()) // wrap-around
    {
        playerPos.pos->x = 2;
    }
    else if (playerPos.pos->x <= 1)
    {
        playerPos.pos->x = 18;
    }

    else if (playerPos.pos->y >= mainGameMechsRef->getBoardSizeY())
    {
        playerPos.pos->y = 2;
    }
    else if (playerPos.pos->y == 1)
    {
        playerPos.pos->y = 8;
    }
}

// More methods to be added