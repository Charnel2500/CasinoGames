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
    playerResult player1;
    playerResult opponent1;
    opponent1.playerName = "Daniel Negreanu";
    player1.playerName = "";
    cin >> player1.playerName;
    //makePlayer(playerName, age, gender);
    //Welcome(playerName);
    std::cout << "In which game do you want to play: 1. Tic tac toe, 2. Hangman, 3. Dice Poker, 4. Tarot. " << endl;
    int choosingGame;
    cin >> choosingGame;
    switch (choosingGame) {
        case 1:
            std::cout << "You chose Tic tac toe.\n";
            gameTicTacToe(arrXO);
            break;
            
        case 2:
            std::cout << "You chose Hangman\n";
            gameHangman(wordBase);
            break;
            
        case 3:
            std::cout << "You chose Dice Poker\n";

            dicePokerGame(player1.diceResult, opponent1.diceResult);
            break;
            
        case 4:
            std::cout << "You chose Tarot\n";
            welcomeTarot();
            readTarotCard();
            break;
            
        default:
            std::cout << "Wrong number\n";
            break;
    }
//    std::cout << playerName << std::endl;
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

    

    
    
    
    
    

    return 0;
}
