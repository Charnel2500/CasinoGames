#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <unistd.h>
#include "dicePoker.h"



//pomysl o stworzeniu dwóch graczy.
void welcomeDicePoker(){
    std::cout << "Welcome in Dice Poker game!" << std::endl;
}
/*
 * 
 * 
 * 
 * void firstRollDice(int (&arr)[MAX_HAND]) {
    srand(time(NULL));
    for (int i = 0; i < MAX_HAND; ++i) 
    {
        int singleDiceRoll = (rand() % 6) + 1;
        arr[i] = singleDiceRoll;
    }
}
*/
void firstRollDice(int* arr) {
    std::random_device rd;  // Inicjalizacja generatora losowego
    std::mt19937 gen(rd());  // Inicjalizacja generatora Mersenne Twister

    std::uniform_int_distribution<int> diceRoll(1, 6);  // Zakres liczb losowych od 1 do 6

    for (int i = 0; i < MAX_HAND; ++i) {
        arr[i] = diceRoll(gen);  // Generowanie liczby losowej
    }
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


bool twoPairs(int a1[]) {
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
            return false; // jest remis ale zaimplementujesz tutaj funkcję, która ponownie rzuca kośćmi
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
                return false; // jest remis ale zaimplementujesz tutaj funkcję, która ponownie rzuca kośćmi
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
                        return false; // jest remis ale zaimplementujesz tutaj funkcję, która ponownie rzuca kośćmi
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
                        return false; // jest remis ale zaimplementujesz tutaj funkcję, która ponownie rzuca kośćmi
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
                                return false; // jest remis ale zaimplementujesz tutaj funkcję, która ponownie rzuca kośćmi
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
                                return false; // jest remis ale zaimplementujesz tutaj funkcję, która ponownie rzuca kośćmi
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
                                    return false; // jest remis ale zaimplementujesz tutaj funkcję, która ponownie rzuca kośćmi
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
                                        return false; // jest remis ale zaimplementujesz tutaj funkcję, która ponownie rzuca kośćmi
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
void dicePokerGame(int* arr1, int* arr2) {
    char playAgain;
    do {
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
    if (winLose(arr1, arr2)==1)
        std::cout << "You won. Congratulation!" << std::endl;
    else
        std::cout << "You lost. You suck!" << std::endl;
    std::cout << "Do you want play again. Write y if yes." << std::endl;
    std::cin >> playAgain;
    } while (playAgain == 'y');
}
