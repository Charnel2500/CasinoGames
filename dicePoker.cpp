#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <unistd.h>
#include <unordered_map>
#include "dicePoker.h"



//pomysl o stworzeniu dwóch graczy.
void welcomeDicePoker(){
    std::cout << "Welcome in Dice Poker game!\n\n" << std::endl;
    std::cout << "██████╗░██╗░█████╗░███████╗  ██████╗░░█████╗░██╗░░██╗███████╗██████╗░" << std::endl; //https://fsymbols.com/generators/carty/
    std::cout << "██╔══██╗██║██╔══██╗██╔════╝  ██╔══██╗██╔══██╗██║░██╔╝██╔════╝██╔══██╗" << std::endl;
    std::cout << "██║░░██║██║██║░░╚═╝█████╗░░  ██████╔╝██║░░██║█████═╝░█████╗░░██████╔╝" << std::endl;
    std::cout << "██║░░██║██║██║░░██╗██╔══╝░░  ██╔═══╝░██║░░██║██╔═██╗░██╔══╝░░██╔══██╗" << std::endl;
    std::cout << "██████╔╝██║╚█████╔╝███████╗  ██║░░░░░╚█████╔╝██║░╚██╗███████╗██║░░██║" << std::endl;
    std::cout << "╚═════╝░╚═╝░╚════╝░╚══════╝  ╚═╝░░░░░░╚════╝░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝\n\n" << std::endl;
}
void firstRollDice(int* arr) {
    std::random_device rd;  // Inicjalizacja generatora losowego
    std::mt19937 gen(rd());  // Inicjalizacja generatora Mersenne Twister

    std::uniform_int_distribution<int> diceRoll(1, 6);  // Zakres liczb losowych od 1 do 6

    for (int i = 0; i < MAX_HAND; ++i) {
        arr[i] = diceRoll(gen);  // Generowanie liczby losowej
    }
}

int diceRollGenerator() {
    std::random_device rd;  // Inicjalizacja generatora losowego
    std::mt19937 gen(rd());  // Inicjalizacja generatora Mersenne Twister
    std::uniform_int_distribution<int> diceRoll(1, 6);  // Zakres liczb losowych od 1 do 6
    return diceRoll(gen);
}
void rollSpecificDiceAgain(int* arr) {
    std::cout << "You may roll the selected dice again. Your dice values: " << std::endl;
    showRollResult(arr);
    int decision = 0;
    std::cout << "Do you want to roll the first dice again (1 - yes, 0 - no)?" << std::endl;
    std::cin >> decision;
    if (decision == 1) {
        arr[0] = diceRollGenerator();
    }
    std::cout << "Do you want to roll the second dice again (1 - yes, 0 - no)?" << std::endl;
    std::cin >> decision;
    if (decision == 2) {
        arr[1] = diceRollGenerator();
    }
    std::cout << "Do you want to roll the third dice again (1 - yes, 0 - no)?" << std::endl;
    std::cin >> decision;
    if (decision == 3) {
        arr[2] = diceRollGenerator();
    }
    std::cout << "Do you want to roll the fourth dice again (1 - yes, 0 - no)?" << std::endl;
    std::cin >> decision;
    if (decision == 4) {
        arr[3] = diceRollGenerator();
    }
    std::cout << "Do you want to roll the fifth dice again (1 - yes, 0 - no)?" << std::endl;
    std::cin >> decision;
    if (decision == 5) {
        arr[4] = diceRollGenerator();
    }
    std::cout << "You rolled the dice again. Here are your results: " << std::endl;
    showRollResult(arr);
}

int findLeastFrequentIndex(int* arr) {
    std::unordered_map<int, int> frequencyMap;
    
    for (int i = 0; i < MAX_HAND; ++i) {
        frequencyMap[arr[i]]++;
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

int findMostFrequentValue(int* arr) {
    std::unordered_map<int, int> frequencyMap;
    
    for (int i = 0; i < MAX_HAND; ++i) {
        frequencyMap[arr[i]]++;
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

void rollTheDiceAgainPairOrThreeOfKind(int* arr) {
    for (int i = 0; i < MAX_HAND; ++i) {
        if (arr[i] != findMostFrequentValue(arr)) {
            arr[findDifferentPosition(arr)] =  diceRollGenerator();
        }
    }
}
    

int findDifferentPosition(int* arr)
{
    int pos = -1;
    for (int i = 0; i < MAX_HAND; ++i)
    {
        int num = arr[i];
        bool isUnique = true;
        for (int j = 0; j < MAX_HAND; ++j)
        {
            if (i != j && arr[j] == num)
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
int computerRollSpecificDiceAgain(int* arr) 
{
    std::cout << "The computer now decides whether to roll the dice again." << std::endl;
    if (numberRepeats(arr)==5) {
        std::cout << "Computer will not roll the dice again." << std::endl;
        return 0;
    }
    if (numberRepeats(arr)==4) {
        arr[findDifferentPosition(arr)] = diceRollGenerator();
        return 0;
    }
    if (fullHouse(arr) == true) {
        std::cout << "Computer will not roll the dice again." << std::endl;
        return 0;
    }
    if (numberRepeats(arr) == 1) {
        std::cout << "Computer will not roll the dice again." << std::endl;
        return 0;
    }
    if (twoPairs(arr) == true) {
        arr[findLeastFrequentIndex(arr)] = diceRollGenerator();
        return 0;
    }
    if (numberRepeats(arr) == 3 || numberRepeats(arr) == 2) {
        rollTheDiceAgainPairOrThreeOfKind(arr);
    }
    else {
        firstRollDice(arr);
    }
    return 0;
}



void rollDiceAgain (int* arr1, int* arr2) //when there is a draw player and opponent roll the dice again and they can't roll specific dice again it is just pure luck.
{
    std::cout << "There is a draw. You and your opponent will roll the dice again and you will not roll specific dice again it is just pure luck." << std::endl;
    std::cout << "The player rolls the dice" << std::endl;
    sleep(1);
    std::cout << "3.." << std::endl;
    sleep(1);
    std::cout << "2.." << std::endl;
    sleep(1);
    std::cout << "1.." << std::endl;
    sleep(1);
    std::cout << "Let's roll the dice" << std::endl;
    firstRollDice(arr1);
    showRollResult(arr1);
    std::cout << "The opponent rolls the dice" << std::endl;
    firstRollDice(arr2);
    sleep(1);
    std::cout << "3.." << std::endl;
    sleep(1);
    std::cout << "2.." << std::endl;
    sleep(1);
    std::cout << "1.." << std::endl;
    sleep(1);
    std::cout << "Let's roll the dice" << std::endl;
    showRollResult(arr2);
}

void showRollResult(int* arr) {
    for (int i = 0; i < MAX_HAND; ++i) 
    {
        std::cout << "The value of dice number " << i << " equals " << arr[i] << "." << std::endl;
    }
}

int numberRepeats(int a1[]) {
    int repMax = 0;
    for (int i = 0; i < MAX_HAND; ++i){
        int rep = 0;
        for (int j = 0; j < MAX_HAND; ++j) {
            if (a1[i] == a1[j])
                rep++;
        }

        if (rep > repMax)
            repMax = rep;
    }
    return repMax;
}
bool fullHouse(int a1[]) {
    std::sort(a1, a1 + 5);  // Sortowanie tablicy w celu ułatwienia porównań

    if ((a1[0] == a1[2] && a1[3] == a1[4] && a1[2] != a1[3]) ||  // Przypadek: 3, 3, 3, X, Y
        (a1[0] == a1[1] && a1[2] == a1[4] && a1[1] != a1[2])) {  // Przypadek: X, X, Y, Y, Y
        return true;
    }

    return false;
}

        

bool twoPairs(int a1[]) { //checking if there are two pairs of dice with the same values 
    if (((a1[0] == a1[1] && a1[2] == a1[3]) || (a1[0] == a1[2] && a1[1] == a1[3]) || (a1[0] == a1[3] && a1[1] == a1[4])) || (a1[1] == a1[2] && a1[3] == a1[4]) || (a1[0] == a1[1] && a1[3] == a1[4]))
        return true;
    return false;
}

int valueHighestRepeats(int a1[]){
    int max = 0;
    for (int i = 0; i < MAX_HAND; ++i){
        if (a1[i] > max)
                max = a1[i];
        }
    return max;
    
} 

int sumValue(int a1[]){
    int sum = 0;
    for (int i = 0; i < MAX_HAND; ++i){
        sum+=a1[i];
    }
    return sum;
}


bool winLose(int a1[], int b1[]){ //check the result, return true if you win, return false f you lose, there is no draw you roll the dice until someone will win.
    if (numberRepeats(a1) == 5 && numberRepeats(b1) < 5) { // 5 the same
        return true;
    }
    else if (numberRepeats(b1) == 5 && numberRepeats(a1) < 5) {
        return false;
    }
    else if (numberRepeats(a1) == 5 && numberRepeats(b1) == 5) {
        if (valueHighestRepeats(a1) > valueHighestRepeats(b1)) {
            return true;
        }
        else if (valueHighestRepeats(a1) < valueHighestRepeats(b1)) {
            return false;
        }
        else if (valueHighestRepeats(a1) == valueHighestRepeats(b1))
        {
            rollDiceAgain(a1, b1); 
        }
    }
    else {
        if (numberRepeats(a1) == 4 && numberRepeats(b1) < 4) { // 4 the same
            return true;
        }
        else if (numberRepeats(b1) == 4 && numberRepeats(a1) < 4) {
            return false;
        }
        else if (numberRepeats(a1) == 4 && numberRepeats(b1) == 4) {
            if (valueHighestRepeats(a1) > valueHighestRepeats(b1)) {
                return true;
            }
            else if (valueHighestRepeats(a1) < valueHighestRepeats(b1)) {
                return false;
            }
            else if (valueHighestRepeats(a1) == valueHighestRepeats(b1))
            {
                rollDiceAgain(a1, b1); 
            }
        }
        else {
            if ((fullHouse(a1) == true) && (fullHouse(b1) != true)) {
                return true;
            }
            else if ((fullHouse(a1) != true) && (fullHouse(b1) == true)) {
                return false;
            }
            else if ((fullHouse(a1) == true) && (fullHouse(b1) == true)) {
                if (valueHighestRepeats(a1) > valueHighestRepeats(b1)) {
                    return true;
                }
                else if (valueHighestRepeats(a1) < valueHighestRepeats(b1)) {
                    return false;
                }
                else if (valueHighestRepeats(a1) == valueHighestRepeats(b1))
                {
                    if (sumValue(a1) > sumValue(b1)) {
                        return true;
                    }
                    else if (sumValue(a1) < sumValue(b1)) {
                        return false;
                    }
                    else if (sumValue(a1) == sumValue(b1)) {
                        rollDiceAgain(a1, b1); 
                    }
                }
            }
            else {
                if (numberRepeats(a1) == 1 && numberRepeats(b1) != 1) {    //straight
                    return true;
                }
                else if (numberRepeats(a1) != 1 && numberRepeats(b1) == 1) {
                    return false;
                }
                else if (numberRepeats(a1) == 1 && numberRepeats(b1) == 1) {    //now check higher straight
                    if (valueHighestRepeats(a1) > valueHighestRepeats(b1)) {
                        return true;
                    }
                    else if (valueHighestRepeats(a1) < valueHighestRepeats(b1)) {
                        return false;
                    }
                    else if (valueHighestRepeats(a1) == valueHighestRepeats(b1))
                    {
                        rollDiceAgain(a1, b1); 
                    }
                }
                else {
                    if ((fullHouse(a1) == true) && (fullHouse(b1) != true)) {
                        return true;
                    }
                    else if ((fullHouse(a1) != true) && (fullHouse(b1) == true)) {
                        return false;
                    }
                    else if ((fullHouse(a1) == true) && (fullHouse(b1) == true)) {
                        if (valueHighestRepeats(a1) > valueHighestRepeats(b1)) {
                            return true;
                        }
                        else if (valueHighestRepeats(a1) < valueHighestRepeats(b1)) {
                            return false;
                        }
                        else if (valueHighestRepeats(a1) == valueHighestRepeats(b1))
                        {
                            if (sumValue(a1) > sumValue(b1)) {
                                return true;
                            }
                            else if (sumValue(a1) < sumValue(b1)) {
                                return false;
                            }
                            else if (sumValue(a1) == sumValue(b1)) {
                                rollDiceAgain(a1, b1); 
                            }
                        }
                    }
                    else if ((twoPairs(a1) == true) && (twoPairs(b1) != true)) {
                        return true;
                    }
                    else if ((twoPairs(a1) != true) && (twoPairs(b1) == true)) {
                        return false;
                    }
                    else if ((twoPairs(a1) == true) && (twoPairs(b1) == true)) {
                        if (valueHighestRepeats(a1) > valueHighestRepeats(b1)) {
                            return true;
                        }
                        else if (valueHighestRepeats(a1) < valueHighestRepeats(b1)) {
                            return false;
                        }
                        else if (valueHighestRepeats(a1) == valueHighestRepeats(b1))
                        {
                            if (sumValue(a1) > sumValue(b1)) {
                                return true;
                            }
                            else if (sumValue(a1) < sumValue(b1)) {
                                return false;
                            }
                            else if (sumValue(a1) == sumValue(b1)) {
                                rollDiceAgain(a1, b1); 
                            }
                        }
                    }
                    else {
                        if (numberRepeats(a1) == 3 && numberRepeats(b1) < 3) {
                            return true;
                        }
                        else if (numberRepeats(b1) == 3 && numberRepeats(a1) < 3) {
                            return false;
                        }
                        else if (numberRepeats(a1) == 3 && numberRepeats(b1) == 3) {
                            if (valueHighestRepeats(a1) > valueHighestRepeats(b1)) {
                                return true;
                            }
                            else if (valueHighestRepeats(a1) < valueHighestRepeats(b1)) {
                                return false;
                            }
                            else if (valueHighestRepeats(a1) == valueHighestRepeats(b1))
                            {
                                if (sumValue(a1) > sumValue(b1)) {
                                    return true;
                                }
                                else if (sumValue(a1) < sumValue(b1)) {
                                    return false;
                                }
                                else if (sumValue(a1) == sumValue(b1)) {
                                    rollDiceAgain(a1, b1); 
                                }
                            }
                        }
                        else {
                            if (numberRepeats(a1) == 2 && numberRepeats(b1) < 2) {
                                return true;
                            }
                            else if (numberRepeats(b1) == 2 && numberRepeats(a1) < 2) {
                                return false;
                            }
                            else if (numberRepeats(a1) == 2 && numberRepeats(b1) == 2) {
                                if (valueHighestRepeats(a1) > valueHighestRepeats(b1)) {
                                    return true;
                                }
                                else if (valueHighestRepeats(a1) < valueHighestRepeats(b1)) {
                                    return false;
                                }
                                else if (valueHighestRepeats(a1) == valueHighestRepeats(b1))
                                {
                                    if (sumValue(a1) > sumValue(b1)) {
                                        return true;
                                    }
                                    else if (sumValue(a1) < sumValue(b1)) {
                                        return false;
                                    }
                                    else if (sumValue(a1) == sumValue(b1)) {
                                        rollDiceAgain(a1, b1); 
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
/// implementacja możliwości rzucenia wybranymi koś
int dicePokerGame(int* arr1, int* arr2) {
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
        std::cout << i << ".." << std::endl;
        sleep(1);
    }
    std::cout << "Let's roll the dice" << std::endl;
    firstRollDice(arr1);
    showRollResult(arr1);
    rollSpecificDiceAgain(arr1);
    std::cout << "The opponent rolls the dice" << std::endl;
    sleep(1);
    for (int i = 3; i > 0; --i) {
        std::cout << i << ".." << std::endl;
        sleep(1);
    }
    firstRollDice(arr2);
    std::cout << "Let's roll the dice" << std::endl;
    showRollResult(arr2);
    if (difficultyLevel == 2) 
    {
        computerRollSpecificDiceAgain(arr2);
        showRollResult(arr2);
    }
    if (winLose(arr1, arr2)==1) {
        std::cout << "You won. Congratulation!" << std::endl;
        bankrollPoker += 10;
    }
    else {
        std::cout << "You lost. You suck!" << std::endl;
        bankrollPoker -= 10;
    }
    std::cout << "Do you want play again. Write y if yes." << std::endl;
    std::cin >> playAgain;
    } while (playAgain == 'y');
    return bankrollPoker;
}


///implementacja różnych poziomow trudnosci bardzo latwy nie wymienia kart, sredni wymienia jak przyglup, wysoki wymienia najlepiej jajk tylko sie da
