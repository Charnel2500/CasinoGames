#ifndef DICEPOKER_H_INCLUDED
#define DICEPOKER_H_INCLUDED
const int MAX_HAND = 5;

extern int playerDices[MAX_HAND];
extern int opponentDices[MAX_HAND];

void welcomeDicePoker();
void firstRollDice(int (&arr)[MAX_HAND]);
void showRollResult(int (&arr)[MAX_HAND]);

#endif // DICEPOKER_H_INCLUDED
