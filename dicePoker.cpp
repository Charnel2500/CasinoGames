#include <iostream>
#include <string>
#include "dicePoker.h"


int playerDices[MAX_HAND] = {};
int opponentDices[MAX_HAND] = {};


void welcomeDicePoker(){
    std::cout << "Welcome in Dice Poker game!" << std::endl;
}

void firstRollDice(int (&arr)[MAX_HAND]) {
    srand(time(NULL));
    for (int i = 0; i <= MAX_HAND; ++i) 
    {
        int singleDiceRoll = (rand() % 6) + 1;
        arr[i] = singleDiceRoll;
    }
}

void showRollResult(int (&arr)[MAX_HAND]) {
    for (int i = 0; i <= MAX_HAND; ++i) 
    {
        std::cout << "The value of dice number " << i << " equals " << arr[i] << "." << std::endl;
    }
}
