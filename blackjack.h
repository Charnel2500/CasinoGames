#ifndef BLACKJACK_H_INCLUDED
#define BLACKJACK_H_INCLUDED
struct Card
{
    std::string cardColor;
    std::string cardRank;
    int cardValue;
};

void welcomeBlackjack();
std::vector<Card> initializeDeck();
void showBlackjackCards();
#endif // DICEPOKER_H_INCLUDED
