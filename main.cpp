#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

#include "player.h"
#include "opponent.h"
#include "gameInfo.h"
#include "ticTacToe.h"
#include "hangman.h"
#include "tarot.h"
#include "dicePoker.h"

struct PlayerMoney {
    std::string playerName;
    int bankroll;
};

bool compareByBankroll(const PlayerMoney& a, const PlayerMoney& b) {
    return a.bankroll > b.bankroll;
}

int main() {
    std::string playerName = "";
    int age = 0;
    char gender = 'a';

    Opponent Negreanu("Daniel Negreanu", 45);
    Negreanu.getName();
    Negreanu.getAge();
    Negreanu.setValues("Daniel Negreanu", 45);

    playerResult player1;
    playerResult opponent1;
    opponent1.playerName = "Daniel Negreanu";
    player1.playerName = "";

    std::cout << "What is your name?" << std::endl;
    std::cin >> playerName;
    player1.playerName = playerName;
    std::cout << "Your opponent's name is " << opponent1.playerName << std::endl;
    std::cout << "Which game do you want to play: 1. Tic Tac Toe, 2. Hangman, 3. Dice Poker, 4. Tarot?" << std::endl;
    int choosingGame, chooseAgain = 0;
    std::cin >> choosingGame;

    int bankroll = 0;

    do {
        switch (choosingGame) {
            case 1:
                std::cout << "You chose Tic Tac Toe." << std::endl;
                bankroll += gameTicTacToe(arrXO);
                break;

            case 2:
                std::cout << "You chose Hangman." << std::endl;
                bankroll += gameHangman(wordBase);
                break;

            case 3:
                std::cout << "You chose Dice Poker." << std::endl;
                bankroll += dicePokerGame(player1.diceResult, opponent1.diceResult);
                break;

            case 4:
                std::cout << "You chose Tarot." << std::endl;
                readTarotCard();
                break;

            default:
                std::cout << "Wrong number." << std::endl;
                break;
        }

        std::cout << "Do you want to play again? Enter 1 for yes, 0 for no." << std::endl;
        std::cin >> chooseAgain;

        if (chooseAgain == 0)
            break;

        std::cout << "Which game do you want to play: 1. Tic Tac Toe, 2. Hangman, 3. Dice Poker, 4. Tarot?" << std::endl;
        std::cin >> choosingGame;
    } while (chooseAgain == 1);

    std::cout << "Your bankroll: " << bankroll << std::endl;

    std::vector<PlayerMoney> data;

    std::ifstream inputFile("results.txt");
    if (inputFile.is_open()) {
        std::string playerName;
        int bankroll;

        while (inputFile >> playerName >> bankroll) {
            data.push_back({playerName, bankroll});
        }
        inputFile.close();
    }

    bool playerExists = false;
    int currentPlayerBankroll = bankroll;

    for (auto& player : data) {
        if (player.playerName == player1.playerName) {
            player.bankroll += currentPlayerBankroll;
            playerExists = true;
            break;
        }
    }

    if (!playerExists) {
        data.push_back({player1.playerName, currentPlayerBankroll});
    }

    std::sort(data.begin(), data.end(), compareByBankroll);

    std::ofstream outputFile("results.txt");
    if (outputFile.is_open()) {
        for (const auto& d : data) {
            outputFile << d.playerName << " " << d.bankroll << "\n";
        }
        outputFile.close();
    } else {
        std::cout << "Can't open file results.txt" << std::endl;
        return 1;
    }

    for (const auto& d : data) {
        std::cout << d.playerName << " " << d.bankroll << "\n";
    }

    return 0;
}
