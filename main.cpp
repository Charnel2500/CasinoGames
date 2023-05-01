#include <iostream>
#include <string>
#include "player.h"
#include "opponent.h"
#include "gameInfo.h"
#include "ticTacToe.h"
#include "hangman.h"

std::string playerName = "";
int age = 0;
char gender = 'a';

//zrób na szybko funkcję tworzącą gracza potem go wpakujesz do osobnej klasy



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Opponent Negreanu ("Daniel Negreanu", 45);
	Negreanu.getName();
	Negreanu.getAge();
    Negreanu.setValues("Daniel Negreanu", 45);
    //makePlayer(playerName, age, gender);
    //Welcome(playerName);

    std::cout << playerName << std::endl;
//    drawBoards(arrXO);
//    menu();
//    std::cout << whoBegin() << std::endl;
 //   std::cout << isFieldFree(chosenField, arrXO) << std::endl;
 //   playerMove(arrXO);
//    playerMove(arrXO);
//    playerMove(arrXO);
//    std::cout << isSomeoneWon(arrXO) << std::endl;

//    computerMove(arrXO);
//    clearBoard(arrXO, 9);
    gameTicTacToe(arrXO);
    hangman();
	return 0;
}
