#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <unistd.h>
#include <unordered_map>
#include "dicePoker.h"



void welcomeDicePoker(){
    std::cout << "Welcome in Dice Poker game!\n\n";
    std::cout << "██████╗░██╗░█████╗░███████╗  ██████╗░░█████╗░██╗░░██╗███████╗██████╗░ \n";
    std::cout << "██╔══██╗██║██╔══██╗██╔════╝  ██╔══██╗██╔══██╗██║░██╔╝██╔════╝██╔══██╗ \n";
    std::cout << "██║░░██║██║██║░░╚═╝█████╗░░  ██████╔╝██║░░██║█████═╝░█████╗░░██████╔╝ \n";
    std::cout << "██║░░██║██║██║░░██╗██╔══╝░░  ██╔═══╝░██║░░██║██╔═██╗░██╔══╝░░██╔══██╗ \n";
    std::cout << "██████╔╝██║╚█████╔╝███████╗  ██║░░░░░╚█████╔╝██║░╚██╗███████╗██║░░██║ \n";
    std::cout << "╚═════╝░╚═╝░╚════╝░╚══════╝  ╚═╝░░░░░░╚════╝░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝\n\n" << std::endl;
}
void firstRollDice(std::vector<int>& dice) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> diceRoll(1, 6);

    dice.clear(); 

    for (int i = 0; i < MAX_HAND; ++i) {
        dice.push_back(diceRoll(gen)); 
    }
}
int diceRollGenerator() {
    std::random_device rd;  
    std::mt19937 gen(rd());  
    std::uniform_int_distribution<int> diceRoll(1, 6); 
    return diceRoll(gen);
}
void rollSpecificDiceAgain(std::vector<int>& dice) {
    std::cout << "You may roll the selected dice again. Your dice values:  \n";
    showRollResult(dice);
    int decision = 0;
    std::cout << "Do you want to roll the first dice again (1 - yes, 0 - no)? \n";
    std::cin >> decision;
    if (decision == 1) {
        dice[0] = diceRollGenerator();
    }
    std::cout << "Do you want to roll the second dice again (1 - yes, 0 - no)? \n";
    std::cin >> decision;
    if (decision == 2) {
        dice[1] = diceRollGenerator();
    }
    std::cout << "Do you want to roll the third dice again (1 - yes, 0 - no)? \n";
    std::cin >> decision;
    if (decision == 3) {
        dice[2] = diceRollGenerator();
    }
    std::cout << "Do you want to roll the fourth dice again (1 - yes, 0 - no)? \n";
    std::cin >> decision;
    if (decision == 4) {
        dice[3] = diceRollGenerator();
    }
    std::cout << "Do you want to roll the fifth dice again (1 - yes, 0 - no)? \n";
    std::cin >> decision;
    if (decision == 5) {
        dice[4] = diceRollGenerator();
    }
    std::cout << "You rolled the dice again. Here are your results: " << std::endl;
    showRollResult(dice);
}

int findLeastFrequentIndex(std::vector<int>& dice) {
    std::unordered_map<int, int> frequencyMap;
    
    for (int i = 0; i < MAX_HAND; ++i) {
        frequencyMap[dice[i]]++;
    }
    
    int leastFrequentIndex = -1;
    int leastFrequentCount = MAX_HAND + 1;
    
    for (const auto& pair : frequencyMap) {
        if (pair.second < leastFrequentCount) {
            leastFrequentCount = pair.second;
            leastFrequentIndex = pair.first;
        }
    }
    
    return leastFrequentIndex;
}

int findMostFrequentValue(std::vector<int>& dice) {
    std::unordered_map<int, int> frequencyMap;
    
    for (int i = 0; i < MAX_HAND; ++i) {
        frequencyMap[dice[i]]++;
    }
    
    int mostFrequentValue = 0;
    int maxAppearance = 0;
    
    for (const auto& value: frequencyMap) {
        if(value.second > maxAppearance) {
            mostFrequentValue = value.first;
            maxAppearance = value.second;
        }
    }
    return mostFrequentValue;
}

void rollTheDiceAgainPairOrThreeOfKind(std::vector<int>& dice) {
    for (int i = 0; i < MAX_HAND; ++i) {
        if (dice[i] != findMostFrequentValue(dice)) {
            dice[findDifferentPosition(dice)] =  diceRollGenerator();
        }
    }
}
    

int findDifferentPosition(std::vector<int>& dice)
{
    int pos = -1;
    for (int i = 0; i < MAX_HAND; ++i)
    {
        int num = dice[i];
        bool isUnique = true;
        for (int j = 0; j < MAX_HAND; ++j)
        {
            if (i != j && dice[j] == num)
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique)
        {
            pos = i;
            break;
        }
    }
    return pos;
}
int computerRollSpecificDiceAgain(std::vector<int>& dice) 
{
    std::cout << "The computer now decides whether to roll the dice again. \n";
    if (numberRepeats(dice)==5) {
        std::cout << "Computer will not roll the dice again. \n";
        return 0;
    }
    if (numberRepeats(dice)==4) {
        dice[findDifferentPosition(dice)] = diceRollGenerator();
        return 0;
    }
    if (fullHouse(dice) == true) {
        std::cout << "Computer will not roll the dice again. \n";
        return 0;
    }
    if (numberRepeats(dice) == 1) {
        std::cout << "Computer will not roll the dice again." << std::endl;
        return 0;
    }
    if (twoPairs(dice) == true) {
        dice[findLeastFrequentIndex(dice)] = diceRollGenerator();
        return 0;
    }
    if (numberRepeats(dice) == 3 || numberRepeats(dice) == 2) {
        rollTheDiceAgainPairOrThreeOfKind(dice);
    }
    else {
        firstRollDice(dice);
    }
    return 0;
}



void rollDiceAgain (std::vector<int>& dice, std::vector<int>& dice2) //when there is dice drdicew player dicend opponent roll the dice again dicend they cdicen't roll specific dice again it is just pure luck.
{
    std::cout << "There is a draw. You and your opponent will roll the dice again and you will not roll specific dice again it is just pure luck. \n";
    std::cout << "The player rolls the dice \n";
    sleep(1);
    std::cout << "3.. \n";
    sleep(1);
    std::cout << "2.. \n";
    sleep(1);
    std::cout << "1.. \n";
    sleep(1);
    std::cout << "Let's roll the dice \n";
    firstRollDice(dice);
    showRollResult(dice);
    std::cout << "The opponent rolls the dice \n";
    firstRollDice(dice2);
    sleep(1);
    std::cout << "3.. \n";
    sleep(1);
    std::cout << "2.. \n";
    sleep(1);
    std::cout << "1.. \n";
    sleep(1);
    std::cout << "Let's roll the dice" << std::endl;
    showRollResult(dice2);
}

void showRollResult(std::vector<int>& dice) {
    for (int i = 0; i < MAX_HAND; ++i) 
    {
        std::cout << "The value of dice number " << i << " equals " << dice [i] << "." << std::endl;
    }
}

int numberRepeats(std::vector<int>& dice) {
    int repmax = 0;
    for (int i = 0; i < MAX_HAND; ++i){
        int rep = 0;
        for (int j = 0; j < MAX_HAND; ++j) {
            if (dice[i] == dice[j])
                rep++;
        }

        if (rep > repmax)
            repmax = rep;
    }
    return repmax;
}
bool fullHouse(std::vector<int>& dice) {
    std::sort(dice.begin(), dice.end());  

    if ((dice[0] == dice[2] && dice[3] == dice[4] && dice[2] != dice[3]) ||  // Przypadek: 3, 3, 3, X, Y
        (dice[0] == dice[1] && dice[2] == dice[4] && dice[1] != dice[2])) {  // Przypadek: X, X, Y, Y, Y
        return true;
    }

    return false;
}

        

bool twoPairs(std::vector<int>& dice) { //checking if there are two pairs of a with the saeme values 
    if (((dice[0] == dice[1] && dice[2] == dice[3]) || (dice[0] == dice[2] && dice[1] == dice[3]) || (dice[0] == dice[3] && dice[1] == dice[4])) || (dice[1] == dice[2] && dice[3] == dice[4]) || (dice[0] == dice[1] && dice[3] == dice[4]))
        return true;
    return false;
}

int valueHighestRepeats(std::vector<int>& dice){
    int max = 0;
    for (int i = 0; i < MAX_HAND; ++i){
        if (dice[i] > max)
                max = dice[i];
        }
    return max;
    
} 

int sumValue(std::vector<int>& dice){
    int sum = 0;
    for (int i = 0; i < MAX_HAND; ++i){
        sum+=dice[i];
    }
    return sum;
}


bool winLose(std::vector<int>& dice, std::vector<int>& dice2){ //check the result, return true if you win, return false f you lose, there is no drdicew you roll the dice until someone will win.
    if (numberRepeats(dice) == 5 && numberRepeats(dice2) < 5) { // 5 the sdiceme
        return true;
    }
    else if (numberRepeats(dice2) == 5 && numberRepeats(dice) < 5) {
        return false;
    }
    else if (numberRepeats(dice) == 5 && numberRepeats(dice2) == 5) {
        if (valueHighestRepeats(dice) > valueHighestRepeats(dice2)) {
            return true;
        }
        else if (valueHighestRepeats(dice) < valueHighestRepeats(dice2)) {
            return false;
        }
        else if (valueHighestRepeats(dice) == valueHighestRepeats(dice2))
        {
            rollDiceAgain(dice, dice2); 
        }
    }
    else {
        if (numberRepeats(dice) == 4 && numberRepeats(dice2) < 4) { // 4 the sdiceme
            return true;
        }
        else if (numberRepeats(dice2) == 4 && numberRepeats(dice) < 4) {
            return false;
        }
        else if (numberRepeats(dice) == 4 && numberRepeats(dice2) == 4) {
            if (valueHighestRepeats(dice) > valueHighestRepeats(dice2)) {
                return true;
            }
            else if (valueHighestRepeats(dice) < valueHighestRepeats(dice2)) {
                return false;
            }
            else if (valueHighestRepeats(dice) == valueHighestRepeats(dice2))
            {
                rollDiceAgain(dice, dice2); 
            }
        }
        else {
            if ((fullHouse(dice) == true) && (fullHouse(dice2) != true)) {
                return true;
            }
            else if ((fullHouse(dice) != true) && (fullHouse(dice2) == true)) {
                return false;
            }
            else if ((fullHouse(dice) == true) && (fullHouse(dice2) == true)) {
                if (valueHighestRepeats(dice) > valueHighestRepeats(dice2)) {
                    return true;
                }
                else if (valueHighestRepeats(dice) < valueHighestRepeats(dice2)) {
                    return false;
                }
                else if (valueHighestRepeats(dice) == valueHighestRepeats(dice2))
                {
                    if (sumValue(dice) > sumValue(dice2)) {
                        return true;
                    }
                    else if (sumValue(dice) < sumValue(dice2)) {
                        return false;
                    }
                    else if (sumValue(dice) == sumValue(dice2)) {
                        rollDiceAgain(dice, dice2); 
                    }
                }
            }
            else {
                if (numberRepeats(dice) == 1 && numberRepeats(dice2) != 1) {    //strdiceight
                    return true;
                }
                else if (numberRepeats(dice) != 1 && numberRepeats(dice2) == 1) {
                    return false;
                }
                else if (numberRepeats(dice) == 1 && numberRepeats(dice2) == 1) {    //now check higher strdiceight
                    if (valueHighestRepeats(dice) > valueHighestRepeats(dice2)) {
                        return true;
                    }
                    else if (valueHighestRepeats(dice) < valueHighestRepeats(dice2)) {
                        return false;
                    }
                    else if (valueHighestRepeats(dice) == valueHighestRepeats(dice2))
                    {
                        rollDiceAgain(dice, dice2); 
                    }
                }
                else {
                    if ((fullHouse(dice) == true) && (fullHouse(dice2) != true)) {
                        return true;
                    }
                    else if ((fullHouse(dice) != true) && (fullHouse(dice2) == true)) {
                        return false;
                    }
                    else if ((fullHouse(dice) == true) && (fullHouse(dice2) == true)) {
                        if (valueHighestRepeats(dice) > valueHighestRepeats(dice2)) {
                            return true;
                        }
                        else if (valueHighestRepeats(dice) < valueHighestRepeats(dice2)) {
                            return false;
                        }
                        else if (valueHighestRepeats(dice) == valueHighestRepeats(dice2))
                        {
                            if (sumValue(dice) > sumValue(dice2)) {
                                return true;
                            }
                            else if (sumValue(dice) < sumValue(dice2)) {
                                return false;
                            }
                            else if (sumValue(dice) == sumValue(dice2)) {
                                rollDiceAgain(dice, dice2); 
                            }
                        }
                    }
                    else if ((twoPairs(dice) == true) && (twoPairs(dice2) != true)) {
                        return true;
                    }
                    else if ((twoPairs(dice) != true) && (twoPairs(dice2) == true)) {
                        return false;
                    }
                    else if ((twoPairs(dice) == true) && (twoPairs(dice2) == true)) {
                        if (valueHighestRepeats(dice) > valueHighestRepeats(dice2)) {
                            return true;
                        }
                        else if (valueHighestRepeats(dice) < valueHighestRepeats(dice2)) {
                            return false;
                        }
                        else if (valueHighestRepeats(dice) == valueHighestRepeats(dice2))
                        {
                            if (sumValue(dice) > sumValue(dice2)) {
                                return true;
                            }
                            else if (sumValue(dice) < sumValue(dice2)) {
                                return false;
                            }
                            else if (sumValue(dice) == sumValue(dice2)) {
                                rollDiceAgain(dice, dice2); 
                            }
                        }
                    }
                    else {
                        if (numberRepeats(dice) == 3 && numberRepeats(dice2) < 3) {
                            return true;
                        }
                        else if (numberRepeats(dice2) == 3 && numberRepeats(dice) < 3) {
                            return false;
                        }
                        else if (numberRepeats(dice) == 3 && numberRepeats(dice2) == 3) {
                            if (valueHighestRepeats(dice) > valueHighestRepeats(dice2)) {
                                return true;
                            }
                            else if (valueHighestRepeats(dice) < valueHighestRepeats(dice2)) {
                                return false;
                            }
                            else if (valueHighestRepeats(dice) == valueHighestRepeats(dice2))
                            {
                                if (sumValue(dice) > sumValue(dice2)) {
                                    return true;
                                }
                                else if (sumValue(dice) < sumValue(dice2)) {
                                    return false;
                                }
                                else if (sumValue(dice) == sumValue(dice2)) {
                                    rollDiceAgain(dice, dice2); 
                                }
                            }
                        }
                        else {
                            if (numberRepeats(dice) == 2 && numberRepeats(dice2) < 2) {
                                return true;
                            }
                            else if (numberRepeats(dice2) == 2 && numberRepeats(dice) < 2) {
                                return false;
                            }
                            else if (numberRepeats(dice) == 2 && numberRepeats(dice2) == 2) {
                                if (valueHighestRepeats(dice) > valueHighestRepeats(dice2)) {
                                    return true;
                                }
                                else if (valueHighestRepeats(dice) < valueHighestRepeats(dice2)) {
                                    return false;
                                }
                                else if (valueHighestRepeats(dice) == valueHighestRepeats(dice2))
                                {
                                    if (sumValue(dice) > sumValue(dice2)) {
                                        return true;
                                    }
                                    else if (sumValue(dice) < sumValue(dice2)) {
                                        return false;
                                    }
                                    else if (sumValue(dice) == sumValue(dice2)) {
                                        rollDiceAgain(dice, dice2); 
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

int dicePokerGame(std::vector<int>& dice, std::vector<int>& dice2) {
    int bankrollPoker = 0;
    welcomeDicePoker();
    char playAgain;
    int difficultyLevel = 0;
    do {
        while (true) {
            std::cout << "Choose difficulty level: 1 - easy, 2 - hard" << std::endl;
            std::cin >> difficultyLevel;

            if (difficultyLevel == 1 || difficultyLevel == 2) {
                break; 
            } else {
                std::cout << "Wrong number! Try again!" << std::endl;
            }
    }
    std::cout << "The player rolls the dice" << std::endl;
    sleep(1);
    for (int i = 3; i > 0; --i) {
        std::cout << i << ".. \n";
        sleep(1);
    }
    std::cout << "Let's roll the dice \n";
    firstRollDice(dice);
    showRollResult(dice);
    rollSpecificDiceAgain(dice);
    std::cout << "The opponent rolls the dice \n";
    sleep(1);
    for (int i = 3; i > 0; --i) {
        std::cout << i << ".. \n";
        sleep(1);
    }
    firstRollDice(dice2);
    std::cout << "Let's roll the dice \n";
    showRollResult(dice2);
    if (difficultyLevel == 2) 
    {
        computerRollSpecificDiceAgain(dice2);
        showRollResult(dice2);
    }
    if (winLose(dice, dice2)==1) {
        std::cout << "You won. Congratulation! \n";
        bankrollPoker += 10;
    }
    else {
        std::cout << "You lost. You suck! \n";
        bankrollPoker -= 10;
    }
    std::cout << "Do you want play again. Write y if yes." << std::endl;
    std::cin >> playAgain;
    } while (playAgain == 'y');
    return bankrollPoker;
}
