#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED
const int MAX_N = 9;
extern char arrXO[];
extern int chosenField;


void drawBoards(char (&arr)[]) ;
bool whoBegin();
bool isFieldFree(int chosenField, char arrXO[]);
void playerMove(char (&arr)[]);
void computerMove(char (&arr)[]);
void clearBoard(char (&arr)[], const int MAX_N);
bool isSomeoneWon(char (&arr)[]);
void gameTicTacToe(char (&arr)[]);
#endif // TICTACTOE_H_INCLUDED
