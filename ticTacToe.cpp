#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "ticTacToe.h"


//implementation of Tic Tac Toe game.
char arrXO[MAX_N] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int chosenField = 0; 


void drawBoards(char (&arr)[]) 
{
    std::cout << arr[0] << "|" << arr[1] << "|" << arr[2] << "|" << std::endl;
    std::cout << "-+-+-+" << std::endl;
    std::cout << arr[3] << "|" << arr[4] << "|" << arr[5] << "|" << std::endl;
    std::cout << "-+-+-+" << std::endl;
    std::cout << arr[6] << "|" << arr[7] << "|" << arr[8] << "| \n" << std::endl;
}

bool whoBegin()
{
    int randNum = rand() % 2;
    std::cout << randNum << std::endl;
    if (randNum == 1)
    {
        std::cout << "Player begins!" << std::endl;
        return true;
    }
    else if (randNum == 0)
    {
        std::cout << "Computer begins!" << std::endl;
        return false;
    }
    else {
        std::cout << "Error: could not determine who begins!" << std::endl;
        return false;
    }
}

bool isFieldFree(int field, char arr[]) {
    if (arr[field] != 'X' || arr[field] != 'O') {
        return true;
    }
    else {
        return false;
    }
}

void playerMove(char (&arr)[]) {
    int chosenField;
    std::cout << "\n\n\n" << std::endl;
    std::cout << "Choose number from 1 to 9" << std::endl;
    drawBoards(arr);
    std::cin >> chosenField;
    std::cout << "You chose field number " << chosenField << "." << std::endl;
    arr[chosenField-1] = 'X';
    drawBoards(arr);
    sleep(2);
}

void computerMove(char (&arr)[]) {
    int randNum;    
    do {
    randNum = rand() % 9;
    }
    while (isFieldFree(randNum, arr) == false);
    arr[randNum] = 'O';    
    std::cout << "Computer chose number: " << randNum+1 << std::endl;
    drawBoards(arr);
    sleep(2);
}

void clearBoard(char (&arr)[], const int MAX_N) {
    for (int i = 0; i < MAX_N; i++) {
        arr[i] = i + 49; // '1' to 49 w ASCII
    }
    std::cout << "Your board is clean right now."<< std::endl;    
    drawBoards(arr);
}
bool isSomeoneWon(char (&arr)[]) {
    if ((arr[0] == 'X' && arr[1] == 'X' && arr[2] == 'X') || 
        (arr[3] == 'X' && arr[4] == 'X' && arr[5] == 'X') ||
        (arr[6] == 'X' && arr[7] == 'X' && arr[8] == 'X') ||
        (arr[0] == 'X' && arr[3] == 'X' && arr[6] == 'X') ||
        (arr[1] == 'X' && arr[4] == 'X' && arr[7] == 'X') ||
        (arr[2] == 'X' && arr[5] == 'X' && arr[8] == 'X') ||
        (arr[0] == 'X' && arr[4] == 'X' && arr[8] == 'X') ||
        (arr[2] == 'X' && arr[4] == 'X' && arr[6] == 'X')) {
        std::cout << "Game over. You win!" << std::endl;
        return true;
    }
    else if ((arr[0] == 'O' && arr[1] == 'O' && arr[2] == 'O') || 
        (arr[3] == 'O' && arr[4] == 'O' && arr[5] == 'O') ||
        (arr[6] == 'O' && arr[7] == 'O' && arr[8] == 'O') ||
        (arr[0] == 'O' && arr[3] == 'O' && arr[6] == 'O') ||
        (arr[1] == 'O' && arr[4] == 'O' && arr[7] == 'O') ||
        (arr[2] == 'O' && arr[5] == 'O' && arr[8] == 'O') ||
        (arr[0] == 'O' && arr[4] == 'O' && arr[8] == 'O') ||
        (arr[2] == 'O' && arr[4] == 'O' && arr[6] == 'O')) {
        std::cout << "Game over. Computer won :(" << std::endl;
        return true;
    }
    else
        return false;
}

void gameTicTacToe(char (&arr)[]) { 
    std::cout << "Welcome in Tic Tac Toe game" << std::endl;
    sleep(2); 
    if (whoBegin() == true) {
        std::cout << "Player begins!" << std::endl;
        while (isSomeoneWon(arr) == false) {
            playerMove(arr);
            if (isSomeoneWon(arr) == true)
                break;
            computerMove(arr);
        }
    }
    else if (whoBegin() == false) {
        std::cout << "Computer begins!" << std::endl;
        while (isSomeoneWon(arr) == false) {
            computerMove(arr);
            if (isSomeoneWon(arr) == true)
                break;
            playerMove(arr);
        }
    }
}

