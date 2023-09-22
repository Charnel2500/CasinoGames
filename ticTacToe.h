#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED
#include <vector> 

extern std::vector<char> numToChoose;

void drawBoards(std::vector<char>& arr);
bool whoBegin(); 
bool isFieldFree(int field, const std::vector<char>& arr); 
void playerMove(std::vector<char>& arr); 
void computerMove(std::vector<char>& arr); 
void clearBoard(std::vector<char>& arr);
bool hasAnyoneWon(const std::vector<char>& arr, int& bankrollTictactoe);
int gameTicTacToe(std::vector<char>& arr);

#endif // TICTACTOE_H_INCLUDED

