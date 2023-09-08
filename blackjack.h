#ifndef BLACKJACK_H_INCLUDED
#define BLACKJACK_H_INCLUDED
struct Card
{
    std::string cardColor;
    std::string cardRank;
    int cardValue;
};
extern std::vector<Card> blackjackDeck;
void welcomeBlackjack();
std::vector<Card> initializeDeck();
void showBlackjackCards(const std::vector<Card>& deck);
#endif // BLACKJACK_H_INCLUDED

