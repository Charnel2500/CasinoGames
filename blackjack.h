#ifndef BLACKJACK_H_INCLUDED
#define BLACKJACK_H_INCLUDED
struct Card
{
    std::string cardColor;
    std::string cardRank;
    int cardValue;
};
extern std::vector<Card> blackjackDeck;
extern std::vector<Card> blackjackDeckUsedCards;
void welcomeBlackjack();
std::vector<Card> initializeDeck();
void showBlackjackCards(const std::vector<Card>& deck);
Card drawCard(std::vector<Card>& deck, std::vector<Card>& usedCards);
int blackjackGame(std::vector<Card>& deck, std::vector<Card>& usedCards);
#endif // BLACKJACK_H_INCLUDED

