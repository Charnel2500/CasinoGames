#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED
const int MAX_N = 9;
extern char arrXO[MAX_N];
extern int chosenField;


void drawBoards(char (&arr)[9]) ;
bool whoBegin();
bool isFieldFree(int chosenField, char arrXO[9]);
void playerMove(char (&arr)[9]);
void computerMove(char (&arr)[9]);
void clearBoard(char (&arr)[9], const int MAX_N);
bool isSomeoneWon(char (&arr)[9]);
void gameTicTacToe(char (&arr)[9]);
#endif // TICTACTOE_H_INCLUDED
