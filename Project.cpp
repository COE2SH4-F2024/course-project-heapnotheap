#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000
GameMechs *myGM; //pointer of game mech type, just like int pointers 


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

    while(myGM->getExitFlagStatus() == false)  
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

    myGM = new GameMechs(); //object of game mechanics class, new gives us pointer to the heap allocation 
    //myPlayer = new Player(myGM); means that the player and game mechanics class inteact with each other now 

    exitFlag = false;
}

void GetInput(void)
{
   myGM->getInput(); //getting input from gamemechs 
}

void RunLogic(void)
{
    if(myGM->getInput() == ' ') //if the player puts in an input of space, it exits the gaem 
    {
        myGM->setExitTrue(); 
    }


}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    int rowNum = myGM->getBoardSizeX();
    int rowCol = myGM->getBoardSizeY();


}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();  

    if(myGM->getLoseFlagStatus()) //checking lose flag status 
    {
        MacUILib_printf("You died!"); //printing message when die
    }  
    else
    {
        MacUILib_printf("aw don't quit :("); //printing message if you exit
    }

    MacUILib_printf("\nScore %d\n", myGM->getScore()); //printing score


    delete myGM; //deallocating the objects on the heap, the GameMechs object in this case
    //delete myPlayer , for later when we create a pointer to the instance of object player 

    MacUILib_uninit();
}
