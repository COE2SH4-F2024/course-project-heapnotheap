#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

//Global Pointer Meant to Instantiate a player object on the heap
Player *myPlayer;

GameMechs *myGM;
bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM ->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(); 
    //During initialization, instantiate a player object on the heap and keep its reference in the global pointer
    myPlayer = new Player(myGM); 
    
    exitFlag = false;
}

void GetInput(void)
{
   myGM -> collectAsynchInput();
}

void RunLogic(void)
{
    Player updatePlayerDir();
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 
    objPos playerPos = myPlayer -> getPlayerPos();   
    MacUILib_printf("Player {x, y, sym] = {%d, %d, %c}\n", playerPos.pos ->x, playerPos.pos ->y, playerPos.symbol);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();   

    delete myPlayer;

    MacUILib_uninit();
}
