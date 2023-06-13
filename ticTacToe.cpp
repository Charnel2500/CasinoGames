#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include "ticTacToe.h"


//implementation of Tic Tac Toe game.
char arrXO[MAX_N] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int chosenField = 0; 


void drawBoards(char (&arr)[9]) 
{
    std::cout << arr[0] << "|" << arr[1] << "|" << arr[2] << "|" << std::endl;
    std::cout << "-+-+-+" << std::endl;
    std::cout << arr[3] << "|" << arr[4] << "|" << arr[5] << "|" << std::endl;
    std::cout << "-+-+-+" << std::endl;
    std::cout << arr[6] << "|" << arr[7] << "|" << arr[8] << "| \n" << std::endl;
}

bool whoBegin()
{
    srand(time(NULL));
    int randNum = rand() % 2;
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

bool isFieldFree(int field, char arr[9]) {
    if (arr[field] != 'X' && arr[field] != 'O') {
        return true;
    }
    else {
        return false;
    }
}

void playerMove(char (&arr)[9]) {
    int chosenField;
    std::cout << "\n\n\n" << std::endl;
    do {
        std::cout << "Choose number from 1 to 9" << std::endl;
        drawBoards(arr);
        std::cin >> chosenField;
        std::cout << "You chose field number " << chosenField << "." << std::endl;
        if (isFieldFree(chosenField-1, arr) == true)
        {
            arr[chosenField-1] = 'X';
            break;
        }
        else
            std::cout << "You choose not free field! Try again!" << std::endl;
    } while (isFieldFree(chosenField-1, arr) == true); 
    drawBoards(arr);
    sleep(1);
}

void computerMove(char (&arr)[9]) {
    int randNum;    
    do {
        std::cout << "\n\nWait for computer move!" << std::endl;
        sleep(1);
        srand(time(NULL));
        randNum = (rand() % 9)+1;
        std::cout << "Computer chose number: " << randNum << "." << std::endl;
        if (isFieldFree(randNum-1, arr) == true)
        {
            arr[randNum-1] = 'O';
            break;
        }
        else
            std::cout << "You choose not free field! Try again!" << std::endl;
    } while (isFieldFree(-1, arr) == true);  
    drawBoards(arr);
    sleep(1);
}

void clearBoard(char (&arr)[9], const int MAX_N) {
    for (int i = 0; i < MAX_N; i++) {
        arr[i] = i + 49; // '1' to 49 w ASCII
    }
    std::cout << "Your board is clean right now."<< std::endl;    
    drawBoards(arr);
}
bool isSomeoneWon(char (&arr)[9], int& bankrollTictactoe) {
    if ((arr[0] == 'X' && arr[1] == 'X' && arr[2] == 'X') || 
        (arr[3] == 'X' && arr[4] == 'X' && arr[5] == 'X') ||
        (arr[6] == 'X' && arr[7] == 'X' && arr[8] == 'X') ||
        (arr[0] == 'X' && arr[3] == 'X' && arr[6] == 'X') ||
        (arr[1] == 'X' && arr[4] == 'X' && arr[7] == 'X') ||
        (arr[2] == 'X' && arr[5] == 'X' && arr[8] == 'X') ||
        (arr[0] == 'X' && arr[4] == 'X' && arr[8] == 'X') ||
        (arr[2] == 'X' && arr[4] == 'X' && arr[6] == 'X')) {
        std::cout << "Game over. You win!" << std::endl;
        bankrollTictactoe+=5;
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
        bankrollTictactoe-=5;
        return true;
    }
    else {
        bankrollTictactoe+=0;
        return false;
    }
}

int gameTicTacToe(char (&arr)[9]) { 
    std::cout << "Welcome in Tic Tac Toe game!\n\n" << std::endl;
    std::cout << "████████╗██╗░█████╗░░░░░░░████████╗░█████╗░░█████╗░░░░░░░████████╗░█████╗░███████╗" << std::endl;
    std::cout << "╚══██╔══╝██║██╔══██╗░░░░░░╚══██╔══╝██╔══██╗██╔══██╗░░░░░░╚══██╔══╝██╔══██╗██╔════╝" << std::endl;
    std::cout << "░░░██║░░░██║██║░░╚═╝█████╗░░░██║░░░███████║██║░░╚═╝█████╗░░░██║░░░██║░░██║█████╗░░" << std::endl;
    std::cout << "░░░██║░░░██║██║░░██╗╚════╝░░░██║░░░██╔══██║██║░░██╗╚════╝░░░██║░░░██║░░██║██╔══╝░░" << std::endl;
    std::cout << "░░░██║░░░██║╚█████╔╝░░░░░░░░░██║░░░██║░░██║╚█████╔╝░░░░░░░░░██║░░░╚█████╔╝███████╗" << std::endl;
    std::cout << "░░░╚═╝░░░╚═╝░╚════╝░░░░░░░░░░╚═╝░░░╚═╝░░╚═╝░╚════╝░░░░░░░░░░╚═╝░░░░╚════╝░╚══════╝\n\n" << std::endl;
    int bankrollTictactoe = 0;
    sleep(2); 
    int cnt = 0;
    if (whoBegin() == true) {
        while (isSomeoneWon(arr, bankrollTictactoe) == false) {
            if (cnt == 9)
                std::cout << "It is a draw" << std::endl;
            playerMove(arr);
            cnt++;
            if (isSomeoneWon(arr, bankrollTictactoe) == true)
                break;
            if (cnt == 9)
                std::cout << "It is a draw" << std::endl;
            computerMove(arr);
            cnt++;
        }
    }
    else if (whoBegin() == false) {
        std::cout << "Computer begins!" << std::endl;
        while (isSomeoneWon(arr, bankrollTictactoe) == false) {
            if (cnt == 9)
                std::cout << "It is a draw" << std::endl;
            computerMove(arr);
            if (isSomeoneWon(arr, bankrollTictactoe) == true)
                break;
            if (cnt == 9)
                std::cout << "It is a draw" << std::endl;
            playerMove(arr);
        }
    }
    return bankrollTictactoe;
}

