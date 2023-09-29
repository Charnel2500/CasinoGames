#ifndef DICEPOKER_H_INCLUDED
#define DICEPOKER_H_INCLUDED
const int MAX_HAND = 5;

struct playerResult {
    std::string playerName;
    std::vector<int> diceResult;
    };

void welcomeDicePoker();
void firstRollDice(std::vector<int>& dice);
int diceRollGenerator();
void rollSpecificDiceAgain(std::vector<int>& dice);
int findLeastFrequentIndex(std::vector<int>& dice);
int findMostFrequentValue(std::vector<int>& dice);
void rollTheDiceAgainPairOrThreeOfKind(std::vector<int>& dice);
int findDifferentPosition(std::vector<int>& dice);
int computerRollSpecificDiceAgain(std::vector<int>& dice);
void rollDiceAgain (std::vector<int>& dice, std::vector<int>& dice2);
void showRollResult(std::vector<int>& dice);
int numberRepeats(std::vector<int>& dice);
bool fullHouse(std::vector<int>& dice);
bool twoPairs(std::vector<int>& dice);
int valueHighestRepeats(std::vector<int>& dice);
int sumValue(std::vector<int>& dice);
bool winLose(std::vector<int>& dice, std::vector<int>& dice2);
int dicePokerGame(std::vector<int>& dice, std::vector<int>& dice2);
#endif // DICEPOKER_H_INCLUDED

