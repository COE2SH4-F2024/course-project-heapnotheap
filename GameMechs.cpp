#include "GameMechs.h"
#include "MacUILib.h" 
#include <time.h>
#include "Player.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = 15; 
    boardSizeY = 30;
    foodPos.setObjPos(2, 3, 'o'); //initializes first food to be outside gameboard
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = boardSizeX;
    boardSizeY = boardSizeY;
    foodPos.setObjPos(2, 3, 'o'); //initializes first food to be outside gameboard
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    //noting on the heap, no deletion needed, Can stay empty for now
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}  

char GameMechs::getInput() 
{
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    
    return input;
}

void GameMechs::collectAsynchInput()
{
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }

    //if(input == ' ')
    //{
      //  setExitTrue();
    //}
}


int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}


void GameMechs::clearInput()
{
    input = 0; 
}

// More methods should be added here



void GameMechs::generateFood(objPos blockOff)
{


    //while food position != player position 

    //random coordinate generation for food
    srand(time(NULL));

    int count = 0;
    //while()
    //{

        foodPos.pos->x = rand() % (boardSizeX - 2) + 1;
        foodPos.pos->y = rand() % (boardSizeY - 2) + 1;

        if((foodPos.pos->x == blockOff.pos->x && foodPos.pos->y == blockOff.pos->y)) //want to access the characters position 
        {
            foodPos.pos->x = rand() % (boardSizeX - 2) + 1;
            foodPos.pos->y = rand() % (boardSizeY - 2) + 1;
        }


    //} 


    
    //if blockOff equals player position
        //regenerate new coordinates within rage 

    //umars weird idea 
    //"lets say it generates a number number and its the player position"
    //"you generate x and y from 0 to less than 1, multiply x by the x random and y by y random"
    //"no matter what since you multiply by 1/different numbers you'll get new coordinates every time"
    //"that would make it so that you get a new number in 2 lines rather than forever"

}


objPos GameMechs::getFoodPos() const
{
    return foodPos;
} 