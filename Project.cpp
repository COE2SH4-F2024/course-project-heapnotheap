#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000
// Global Pointer Meant to Instantiate a player object on the heap
Player *myPlayer;
GameMechs *myGM; // pointer of game mech type, just like int pointers
bool exitFlag;

//testing push pull
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

    while (myGM-> getExitFlagStatus() == false)
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
    //exitFlag = false;
    myGM->generateFood(myPlayer->getPlayerPos());
}

void GetInput(void)
{
    myGM->collectAsynchInput();
}

void RunLogic(void)
{

    myPlayer->movePlayer();

    
    if (myGM->getInput() != '\0')
    {
        myPlayer->updatePlayerDir();
    }
    

    if (myGM->getInput() == ' ') // if the player puts in an input of space, it exits the gaem
    {
        myGM->setExitTrue();
    }
    


}

void DrawScreen(void)
{

    MacUILib_clearScreen(); 
    objPos playerPos = myPlayer -> getPlayerPos();  

    objPos foodPos = myGM-> getFoodPos(); 

    MacUILib_printf("Player {x, y, sym} = {%d, %d, %c}\n", playerPos.pos ->x, playerPos.pos ->y, playerPos.symbol );
    int boardX = myGM-> getBoardSizeX();
    int boardY = myGM-> getBoardSizeY();

    int i, j;

    for (i=0; i<=boardX; i++)
    {

        for(j=0; j<= boardY; j++)
        {
           
            if (j == 0 || j == boardY || i == 0 || i == boardX)
                {
                    MacUILib_printf("#");
                }

           
            else{

                if (i == playerPos.pos ->x && j == playerPos.pos ->y)
                {
                    MacUILib_printf("%c", playerPos.symbol);
                }

                else if(j == foodPos.pos->x  && i == foodPos.pos->y)
                {
                    MacUILib_printf("%c", foodPos.symbol); //printing food symbol
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
    MacUILib_printf("foods current coorinates are [%d, %d]\n", foodPos.pos->x, foodPos.pos->y);
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
