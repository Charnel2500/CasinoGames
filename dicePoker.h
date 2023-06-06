#ifndef DICEPOKER_H_INCLUDED
#define DICEPOKER_H_INCLUDED
const int MAX_HAND = 5;

struct playerResult {
    std::string playerName;
    int diceResult[MAX_HAND];
    };

void welcomeDicePoker();
void firstRollDice(int (&arr)[MAX_HAND]);
void showRollResult(int (&arr)[MAX_HAND]);
int numberRepeats(int a1[]);
bool fullHouse(int a1[]);
bool twoPairs(int a1[]);
int valueHighestRepeats(int a1[]);
int sumValue(int a1[]);
bool winLose(int a1[], int b1[]);
#endif // DICEPOKER_H_INCLUDED
