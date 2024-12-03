#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"


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

    srand(time(NULL));
}

void GetInput(void)
{
    myGM->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    
    /*if (myGM->getInput() != '\0')
    {
        myPlayer->updatePlayerDir();
    }*/
    

    /*if (myGM->getInput() == ' ') // if the player puts in an input of space, it exits the gaem
    {
        myGM->setExitTrue();
    }*/
    


}

void DrawScreen(void)
{

    MacUILib_clearScreen(); 
    objPosArrayList* playerPos = myPlayer -> getPlayerPos();  

    objPos foodPos = myGM-> getFoodPos(); 

    MacUILib_printf("Player {x, y, sym} = {%d, %d, %c}\n", playerPos->getHeadElement().pos->x, playerPos->getHeadElement().pos->y, playerPos->getHeadElement().symbol );
    int boardX = myGM-> getBoardSizeX();
    int boardY = myGM-> getBoardSizeY();

    int i, j;

    for (i=0; i< boardY; i++)
    {

        for(j=0; j< boardX; j++)
        {
           
            if (j == 0 || j == boardX - 1|| i == 0 || i == boardY - 1)
            {
                MacUILib_printf("#");
            }

            
            else if (i ==  playerPos->getHeadElement().pos->y && j == playerPos->getHeadElement().pos->x)
            {
                MacUILib_printf("%c", playerPos->getHeadElement().symbol);
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
            
        
        MacUILib_printf("\n");
    }

    MacUILib_printf("How to play!\nPress A, W, S, D to move 'Moe'\nA: Left, D: Right, W: Up, S: Down\n"); 
    MacUILib_printf("To change the speed press:\nLevel 1: - Level 2: ; Level 3: / Level 4: . Level 5: ,\n"); 
    MacUILib_printf("Your current coordinates are: %d, %d\n", playerPos->getHeadElement().pos->x, playerPos->getHeadElement().pos->y);
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

    if(myGM->getLoseFlagStatus())
    {
        MacUILib_printf("womp womp, try again");
    }

    else
    {
        MacUILib_printf("play again!");
    }

    delete myGM;
    delete myPlayer;

    MacUILib_uninit();
}
