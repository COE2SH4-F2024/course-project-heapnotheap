#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000
// Global Pointer Meant to Instantiate a player object on the heap
Player *myPlayer;
GameMechs *myGM; // pointer of game mech type, just like int pointers
bool exitFlag;

//testing push pull
//sehaj push
// this works -Mahum was here

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void)
{

    Initialize();

    while (myGM->getExitFlagStatus() == false)
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
    myPlayer = new Player(myGM);
    exitFlag = false;
}

void GetInput(void)
{
    myGM->collectAsynchInput();
}

void RunLogic(void)
{

    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    if (myGM->getInput() == ' ') // if the player puts in an input of space, it exits the gaem
    {
        myGM->setExitTrue();
    }

    myPlayer->movePlayer();
}

void DrawScreen(void)
{

    MacUILib_clearScreen(); 
    objPos playerPos = myPlayer -> getPlayerPos();   
    MacUILib_printf("Player {x, y, sym] = {%d, %d, %c}\n", playerPos.pos ->x, playerPos.pos ->y, playerPos.symbol);

    int i, j;

    for (i=0; i<=myGM->getBoardSizeX(); i++)
    {

        for(j=0; j<=myGM->getBoardSizeY(); j++)
        {
            if (i == myPlayer->getPlayerPos().pos->x && j == myPlayer->getPlayerPos().pos->y)
            {
                MacUILib_printf("%c", playerPos.symbol);
            }
        
            else
            {
                if (j == 0 || j == myGM->getBoardSizeY() || i == 0 || i == myGM->getBoardSizeX())
                {
                    MacUILib_printf("#");
                }

                else 
                {
                    MacUILib_printf(" ");
                }
            }
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("How to play!\nPress A, W, S, D to move 'Moe'\nA: Left, D: Right, W: Up, S: Down\n"); 
    MacUILib_printf("To change the speed press:\nLevel 1: - Level 2: ; Level 3: / Level 4: . Level 5: ,\n"); 
    MacUILib_printf("Your current coordinates are: %d, %d\n", playerPos.pos->x, playerPos.pos->y);
    MacUILib_printf("Current key pressed is %c", myGM->getInput()); 

}


void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void)
{
    MacUILib_clearScreen();

    MacUILib_uninit();
}
