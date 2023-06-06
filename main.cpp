#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // Dołącz bibliotekę odpowiedzialną za funkcję sleep
#include <chrono>
#include <thread>
#include "player.h"
#include "opponent.h"
#include "gameInfo.h"
#include "ticTacToe.h"
#include "hangman.h"
#include "tarot.h"
#include "dicePoker.h"


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
//    gameTicTacToe(arrXO);
 //   drawHangman(1);
  //  drawHangman(2);
//    drawHangman(3);
 //   drawHangman(4);
 //   drawHangman(5);
 //   drawHangman(6);
//    drawHangman(7);
//    gameHangman(wordBase);
 //   welcomeTarot();
//    welcomeDicePoker();
 //   readTarotCard();
//    firstRollDice(playerDices);
  //  firstRollDice(opponentDices);
  //  showRollResult(playerDices);
 //   showRollResult(opponentDices);
    playerResult player1;
    playerResult opponent1;
    opponent1.playerName = "Daniel Negreanu";
    player1.playerName = "";
    cin >> player1.playerName;
    std::cout << "First roll the dice" << endl;
    srand(time(NULL));
    sleep(3);
    firstRollDice(player1.diceResult);
    showRollResult(player1.diceResult);
    std::cout << "Second roll the dice" << endl;
    firstRollDice(opponent1.diceResult);
    sleep(3);
    showRollResult(opponent1.diceResult);
    std::cout << "Whose won 1 - player 0 - opponent:" << winLose(player1.diceResult, opponent1.diceResult) << endl;

    
    
    
    
    

    return 0;
}
