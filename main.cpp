#include <iostream>
#include <string>
#include "player.h"
#include "opponent.h"
#include "gameInfo.h"

std::string playerName = "Jakub";
int age = 0;
char gender = 'm';

//zrób na szybko funkcję tworzącą gracza potem go wpakujesz do osobnej klasy

void makePlayer ();


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Opponent Negreanu ("Daniel Negreanu", 45);
	Negreanu.getName();
	Negreanu.getAge();
    Negreanu.setValues("Daniel Negreanu", 45);
    Negreanu.printInfo("Daniel Negreanu", 45);
    playerName = "Jakub";
    Welcome(playerName);
    std::cout << "Hello World! \n\n\n\n\n\n" << std::endl;
    makePlayer();
    
    
    menu();
	return 0;
}

void makePlayer () {
    std::cout << "What is your name? " << std::endl;
    std::cin >> playerName;
    std::cout << "What is your age? " << std::endl;
    std::cin >> age;
    std::cout << "What is yout gende (write m or f)? " << std::endl;
    std::cin >> gender;
    
    std::cout << "You are " << playerName << ". " << "You are " << age << " years old." << std::endl;
    
    if (gender == 'm') 
        std::cout << "You are male." << std::endl;
    else if (gender == 'f')
        std::cout << "You are female." << std::endl;
}

