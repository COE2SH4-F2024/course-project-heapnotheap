#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        objPosArrayList* getPlayerPos() const; // Upgrade this in iteration 3.       
        void updatePlayerDir();
        void movePlayer();

        bool checkFoodConsumption();
        void increasePlayerLength();
        bool checkSelfCollision(); 

        // More methods to be added here

    private:
           
        enum Dir myFSMMode;
        //objPos playerPos;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;

        objPosArrayList* playerPosList;
};

#endif