#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include <unistd.h>
#include <random>
#include "blackjack.h"

std::vector<Card> blackjackDeck;
std::vector<Card> blackjackDeckUsedCards;
std::vector<Card> blackjackDeckComputerCards;
std::vector<Card> blackjackDeckPlayerCards;




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

Card drawCard(std::vector<Card>& deck, std::vector<Card>& usedCards) {
    int randomIndex;
    
    if (deck.empty()) {
        std::cout << "Brak kart do wylosowania. Tasowanie użytych kart." << std::endl;
        
        deck = usedCards;
        usedCards.clear();
        std::random_shuffle(deck.begin(), deck.end());
        
        std::shuffle(deck.begin(), deck.end(), std::default_random_engine(std::time(nullptr)));
    }
    
    randomIndex = std::rand() % deck.size();
    Card drawnCard = deck[randomIndex];
    
    usedCards.push_back(drawnCard);
    
    deck.erase(deck.begin() + randomIndex);
    
    std::cout << "Wylosowano kartę: " << drawnCard.cardColor << " " << drawnCard.cardRank << " " << drawnCard.cardValue << "." << std::endl;
    
    return drawnCard;
}




int blackjackGame(std::vector<Card>& deck, std::vector<Card>& usedCards, std::vector<Card>& blackjackDeckComputerCards, std::vector<Card>& blackjackDeckPlayerCards) {
    int bankrollBlackjack = 0;
    int computerHandValue = 0;
    int playerHandValue = 0;
    int choice;
    welcomeBlackjack();
    char playAgain;
/*    int difficultyLevel = 0;
    do {
        while (true) {
            std::cout << "Choose difficulty level: 1 - easy, 2 - hard" << std::endl;
            std::cin >> difficultyLevel;

            if (difficultyLevel == 1 || difficultyLevel == 2) {
                break; 
            } else {
                std::cout << "Wrong number! Try again!" << std::endl;
            }
    } */ //do zaimplementowania później
    std::cout << "This is opponent hand:" << std::endl;
    sleep(1);
    Card startingComputerCard1 = drawCard(deck, usedCards);
    computerHandValue = startingComputerCard1.cardValue;
    blackjackDeckComputerCards.push_back(startingComputerCard1);
    
    Card startingComputerCard2 = drawCard(deck, usedCards);
    computerHandValue += startingComputerCard1.cardValue;
    blackjackDeckComputerCards.push_back(startingComputerCard2);
    std::cout << "Opponent hand value: " << computerHandValue << std::endl;
    
    Card startingPlayerCard1 = drawCard(deck, usedCards);
    playerHandValue = startingPlayerCard1.cardValue;
    blackjackDeckPlayerCards.push_back(startingPlayerCard1);
    
    Card startingPlayerCard2 = drawCard(deck, usedCards);
    playerHandValue += startingPlayerCard2.cardValue;
    blackjackDeckPlayerCards.push_back(startingPlayerCard2);
    std::cout << "Player hand value: " << playerHandValue << std::endl;
    do {
        std::cout << "You must decide. 1. draw a card, 2. Check your and opponent card, 3. Finish drawing a card" << std::endl; 
        std::cin >> choice;
        if (choice == 1) {
            Card startingPlayerCardMore = drawCard(deck, usedCards);
            playerHandValue += startingPlayerCardMore.cardValue;
            blackjackDeckPlayerCards.push_back(startingPlayerCardMore);
            std::cout << "Player hand value: " << playerHandValue << std::endl;
        }
        else if (choice == 2) {
            std::cout << "Opponent cards" << std::endl;
            showBlackjackCards(blackjackDeckComputerCards);
            std::cout << "Opponent points: " << computerHandValue << std::endl;
            
            std::cout << "Player cards" << std::endl;
            showBlackjackCards(blackjackDeckPlayerCards);
            std::cout << "Player points: " << playerHandValue << std::endl;

        }
        else if (choice == 3) {
            std::cout << "You finish drawing a card. Your points: " << playerHandValue << std::endl;
        }
        else {
            std::cout << "Wrong choice. You must choose. 1. draw a card, 2. Check your and opponent card, 3. Finish drawing a card" << std::endl; 
        }
    } while (choice !=3);
    if (playerHandValue > 21) {
        std::cout << "Computer won!" << std::endl;
        return bankrollBlackjack-=10;
    }
        
    while (computerHandValue > playerHandValue && computerHandValue <=21) {
        Card startingComputerCardMore = drawCard(deck, usedCards);
        computerHandValue += startingComputerCardMore.cardValue;
        blackjackDeckComputerCards.push_back(startingComputerCardMore);
        std::cout << "Player hand value: " << computerHandValue << std::endl;
    }
    if (computerHandValue <= 21 && computerHandValue > playerHandValue) {
        std::cout << "Computer won!" << std::endl;
        return bankrollBlackjack-=10;
    }
    else if (computerHandValue == playerHandValue) {
        return bankrollBlackjack;
    }
    else {
        std::cout << "Player won!" << std::endl;
        return bankrollBlackjack+=10;
    }
}
