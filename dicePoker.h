#ifndef DICEPOKER_H_INCLUDED
#define DICEPOKER_H_INCLUDED
const int MAX_HAND = 5;

struct playerResult {
    std::string playerName;
    int diceResult[MAX_HAND];
    };

void welcomeDicePoker();
void firstRollDice(int* arr);
void rollSpecificDiceAgain(int* arr);
int findLeastFrequentIndex(int* arr);
int findMostFrequentValue(int* arr);
void rollTheDiceAgainPairOrThreeOfKind(int* arr);
int findDifferentPosition(int* arr);
int computerRollSpecificDiceAgain(int* arr);
void rollDiceAgain (int* arr1, int* arr2);
void showRollResult(int* arr);
int numberRepeats(int a1[]);
bool fullHouse(int a1[]);
bool twoPairs(int a1[]);
int valueHighestRepeats(int a1[]);
int sumValue(int a1[]);
bool winLose(int a1[], int b1[]);
void dicePokerGame(int* arr1, int* arr2);
#endif // DICEPOKER_H_INCLUDED
