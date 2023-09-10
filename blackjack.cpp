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




int blackjackGame(std::vector<Card>& deck, std::vector<Card>& usedCards) {
    int bankrollBlackjack = 0;
    int computerHandValue = 0;
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
    Card startingComputerCard2 = drawCard(deck, usedCards);
    computerHandValue += startingComputerCard1.cardValue;
/*
    if (winLose(arr1, arr2)==1) {
        std::cout << "You won. Congratulation!" << std::endl;
        bankrollPoker += 10;
    }
    else {
        std::cout << "You lost. You suck!" << std::endl;
        bankrollPoker -= 10;
    }

    std::cout << "Do you want play again. Write y if yes." << std::endl;
    std::cin >> playAgain;
    } while (playAgain == 'y');    */
    return bankrollBlackjack;
}
