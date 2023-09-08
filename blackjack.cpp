#include <iostream>
#include <vector>
#include "blackjack.h"

void welcomeBlackjack(){
    std::cout << "Welcome in Blackjack game!\n\n" << std::endl;
    std::cout << "██████╗░██╗░░░░░░█████╗░░█████╗░██╗░░██╗░░░░░██╗░█████╗░░█████╗░██╗░░██╗" << std::endl;
    std::cout << "██╔══██╗██║░░░░░██╔══██╗██╔══██╗██║░██╔╝░░░░░██║██╔══██╗██╔══██╗██║░██╔╝" << std::endl;
    std::cout << "██████╦╝██║░░░░░███████║██║░░╚═╝█████═╝░░░░░░██║███████║██║░░╚═╝█████═╝░" << std::endl;
    std::cout << "██╔══██╗██║░░░░░██╔══██║██║░░██╗██╔═██╗░██╗░░██║██╔══██║██║░░██╗██╔═██╗░" << std::endl;
    std::cout << "██████╦╝███████╗██║░░██║╚█████╔╝██║░╚██╗╚█████╔╝██║░░██║╚█████╔╝██║░╚██╗" << std::endl;
    std::cout << "╚═════╝░╚══════╝╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝\n\n" << std::endl;
}

std::vector<Card> initializeDeck() {
    std::vector<Card> deck;
    std::string cardColors[] = {"Spades", "Clubs", "Hearts", "Diamonds"};
    std::string cardRanks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    int cardValues[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

    for (const std::string& cardColor : cardColors) {
        for (const std::string& cardRank : cardRanks) {
            for (const int& cardValue : cardValues) {
                Card card = {cardColor, cardRank, cardValue};
                deck.push_back(card);
            }
        }
    }

    return deck;
}

void showBlackjackCards(const std::vector<Card>& deck) {
    for (const Card& card : deck) {
        std::cout << card.cardColor << " " << card.cardRank << " " << card.cardValue << "." << std::endl;
    }
}
