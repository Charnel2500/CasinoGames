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
    int bankroll = 0;
	Opponent Negreanu ("Daniel Negreanu", 45);
	Negreanu.getName();
	Negreanu.getAge();
    Negreanu.setValues("Daniel Negreanu", 45);
    playerResult player1;
    playerResult opponent1;
    opponent1.playerName = "Daniel Negreanu";
    player1.playerName = "";
    std::cout << "What is your name?" << endl;
    std::cin >> player1.playerName;
    //makePlayer(playerName, age, gender);
    //Welcome(playerName);
    std::cout << "In which game do you want to play: 1. Tic tac toe, 2. Hangman, 3. Dice Poker, 4. Tarot. " << endl;
    int choosingGame, chooseAgain = 0;
    std::cin >> choosingGame;
    do 
    {
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

                bankroll+=dicePokerGame(player1.diceResult, opponent1.diceResult);
                break;
                
            case 4:
                std::cout << "You chose Tarot\n";
                readTarotCard();
                break;
                
            default:
                std::cout << "Wrong number\n";
                break;
        }
        std::cout << "Do you wanna play again: 1 - yes; 0 - no" << std::endl;
        std::cin >> chooseAgain;
        if (chooseAgain == 0)
            break;
        std::cout << "In which game do you want to play: 1. Tic tac toe, 2. Hangman, 3. Dice Poker, 4. Tarot. " << endl;
        std::cin >> choosingGame;
    } while (chooseAgain == 1);
    return 0;
}
