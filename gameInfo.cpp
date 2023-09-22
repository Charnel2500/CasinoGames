#include "gameInfo.h"
#include <iostream>
#include <string>


void Welcome(std::string playerName) {
    std::cout << "Dear " << playerName << "," << std::endl;
std::cout << "On behalf of our entire team at Dice Casino, I would like to extend a warm welcome to you! We are thrilled to have you join our community of avid \
gamers and we hope that your experience with us will be nothing short of amazing.As a new player, we understand that you may have questions or concerns about \
our casino and the games we offer. Please know that our customer service team is always available to answer any queries you may have, and we encourage you to \
reach out to them at any time." << std::endl;
std::cout << "At DiceCasino, we take great pride in offering a wide variety of games, from classic table games like blackjack and roulette to the latest and \
greatest video slots. We strive to provide our players with the best possible gaming experience, with user-friendly interfaces, seamless gameplay, and \
exciting bonus features. But we also understand that responsible gaming is of utmost importance, which is why we have implemented various measures to \
ensure that our players are always safe and secure. We have a strict age verification process in place to prevent underage gambling, and we offer various \
tools to help our players manage their gaming, such as self-exclusion and deposit limits. As a new player, you will also be eligible for some \
fantastic bonuses and promotions. These can include anything from deposit bonuses to free spins, and we encourage you to take advantage of them \
to maximize your playing experience. Once again, we are thrilled to have you join our casino, and we hope that you enjoy your time with us. Should \
you have any questions or feedback, please do not hesitate to contact us. We wish you the best of luck and hope to see you at the tables soon!" << std::endl;
std::cout << "Sincerely," << std::endl;
std::cout << "Master of Game" << std::endl;
}


int menu() {
	int choice = -1;
	while (choice != 4) {
		std::cout << "\nEnter your choice:\n";
		std::cout << "1) Add new player\n";
		std::cout << "2) Print all players\n";
		std::cout << "3) Show welcome again\n";
		std::cout << "4) Exit\n";

		std::cin >> choice;

		if (!(1 <= choice && choice <= 5)) {
			std::cout << "Invalid choice. Try again\n";
			choice = -1;	// loop keep working
		}
		else if (choice == 1)
        {
            std::cout << "Here I will add new player";
        }
		else if (choice == 2)
        {
            std::cout << "Here I will show all players";
        }
		else if (choice == 3)
        {
            std::cout << "Here I will choose a game.";
        }
	}
	return choice;
}

void makePlayer (std::string &playerName, int &age, char &gender) {
    std::cout << "First you need to create a player account."  << std::endl;
    std::cout << "What is your name? " << std::endl;
    std::cin >> playerName;
    std::cout << "What is your age? " << std::endl;
    std::cin >> age;
    std::cout << "What is yout gender (write m or f)? " << std::endl;
    std::cin >> gender;
    
    std::cout << "You are " << playerName << ". " << "You are " << age << " years old." << std::endl;
    
    if (gender == 'm') 
        std::cout << "You are male." << std::endl;
    else if (gender == 'f')
        std::cout << "You are female." << std::endl;
}
