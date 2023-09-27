#include <iostream>
#include <string>
#include <time.h>
#include <SFML/Audio.hpp> 

#include "hangman.h"

std::string wordBase[MAX_NUMBER_CATEGORIES][MAX_NAME_HANGMAN] = {
                        {"lion", "tiger", "elephant", "giraffe", "zebra", 
                        "panda", "monkey", "hippopotamus", "crocodile", "kangaroo",
                        "koala", "rhinoceros", "bear", "wolf", "fox", "deer", 
                        "rabbit", "snake", "shark", "whale"},
                        {"rose", "daisy", "tulip", "sunflower", "cactus",
                        "fern", "ivy", "oak", "willow", "bamboo", 
                        "maple", "pine", "birch", "moss", "thistle", "lavender",
                        "mushroom", "dandelion", "orchid", "lotus"},
                        {"usa", "canada", "mexico", "brazil", "argentina", 
                        "france", "germany", "italy", "spain", "russia",
                        "china", "japan", "korea", "india", "australia",
                        "egypt", "nigeria", "sudan", "kenya", "morocco"}
                        };

void welcomeHangman(){
    std::cout << "Welcome in Hangman game!\n\n\n";
    std::cout << "██╗░░██╗░█████╗░███╗░░██╗░██████╗░███╗░░░███╗░█████╗░███╗░░██╗ \n";
    std::cout << "██║░░██║██╔══██╗████╗░██║██╔════╝░████╗░████║██╔══██╗████╗░██║ \n";
    std::cout << "███████║███████║██╔██╗██║██║░░██╗░██╔████╔██║███████║██╔██╗██║ \n";
    std::cout << "██╔══██║██╔══██║██║╚████║██║░░╚██╗██║╚██╔╝██║██╔══██║██║╚████║ \n";
    std::cout << "██║░░██║██║░░██║██║░╚███║╚██████╔╝██║░╚═╝░██║██║░░██║██║░╚███║ \n";
    std::cout << "╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚══╝░╚═════╝░╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝░░╚══╝\n\n" << std::endl;
    
}
std::string chooseCategoryDrawWord(std::string (&wordBase)[MAX_NUMBER_CATEGORIES][MAX_NAME_HANGMAN])
{
    int chosenCategory;
    srand(time(NULL));
    int drawRandomWord = rand() % 20;
    std::string randomWord;
    std::cout << "Choose category: 1. animals, 2. plants, 3. countries \n";
    std::cin >> chosenCategory;
    if (chosenCategory == 1)
        std::cout << "You chose animals. \n";
    if (chosenCategory == 2)
        std::cout << "You chose plants. \n";
    if (chosenCategory == 3)
        std::cout << "You chose countries." << std::endl;
    randomWord = wordBase[chosenCategory-1][drawRandomWord];
    return randomWord;
    
}

int gameHangman(std::string (&wordBase)[MAX_NUMBER_CATEGORIES][MAX_NAME_HANGMAN]) {
    sf::Music startMusic;
    if (!startMusic.openFromFile("music/hangman.wav")) {
        std::cerr << "Failed to load start music!" << std::endl;
    } else {
        startMusic.play();
        startMusic.setLoop(true);
    }
    welcomeHangman();
    int bankrollHangman = 0;
    std::string drawnWord = chooseCategoryDrawWord(wordBase);
    std::string guessWord = drawnWord;
    char chosenLetter;
    int deathCount = 0;
    for (int i = 0; i < int(drawnWord.length()); ++i)
    {
        guessWord[i] = '_';
    }
    std::cout << guessWord << std::endl;
    while (true)
    {
        bool charPresent = false;
        std::cout << "Choose your letter (only small letters):  \n";
        std::cin >> chosenLetter;
        std::cout << "You chose letter " << chosenLetter << std::endl;
        for (int i = 0; i < int(drawnWord.length()); ++i)
        {
            if (chosenLetter == drawnWord[i])
            {
                guessWord[i] = chosenLetter;
                charPresent = true;
            }
        }
        if (charPresent == false)
            deathCount++;
        
        drawHangman(deathCount);
        std::cout << guessWord << std::endl;
        if (deathCount == 6)
        {
            std::cout << "You lost! You are dead man! \n";
            std::cout << "It was the word " << drawnWord << "."<< std::endl;
            bankrollHangman -= 5;
            break;
        }
        else if (guessWord == drawnWord)
        {
            std::cout << "You won! Congratulations!" << std::endl;
            bankrollHangman += 5;
            break;            
        }
            
    }
    startMusic.stop();
    return bankrollHangman;
}
                        
void drawHangman(int numWrongAnswers) {
    switch(numWrongAnswers) {
    case 0:
        std::cout << "  +---+\n";
        std::cout << "      |\n";
        std::cout << "      |\n";
        std::cout << "      |\n";
        std::cout << "      |\n";
        std::cout << "      |\n";
        std::cout << "========="  << std::endl;
        break;
    case 1:
        std::cout << "  +---+\n";
        std::cout << "  |   |\n";
        std::cout << "  O   |\n";
        std::cout << "      |\n";
        std::cout << "      |\n";
        std::cout << "      |\n";
        std::cout << "========="  << std::endl;
        break;
    case 2:
        std::cout << "  +---+\n";
        std::cout << "  |   |\n";
        std::cout << "  O   |\n";
        std::cout << "  |   |\n";
        std::cout << "      |\n";
        std::cout << "      |\n";
        std::cout << "========="  << std::endl;
        break;
    case 3:
        std::cout << "  +---+\n";
        std::cout << "  |   |\n";
        std::cout << "  O   |\n";
        std::cout << " /|   |\n";
        std::cout << "      |\n";
        std::cout << "      |\n";
        std::cout << "========="  << std::endl;
        break;
    case 4:
        std::cout << "  +---+\n";
        std::cout << "  |   |\n";
        std::cout << "  O   |\n";
        std::cout << " /|\\  |\n";
        std::cout << "      |\n";
        std::cout << "      |\n";
        std::cout << "========="  << std::endl;
        break;
    case 5:
        std::cout << "  +---+\n";
        std::cout << "  |   |\n";
        std::cout << "  O   |\n";
        std::cout << " /|\\  |\n";
        std::cout << " /    |\n";
        std::cout << "      |\n";
        std::cout << "========="  << std::endl;
        break;
    case 6:
        std::cout << "  +---+\n";
        std::cout << "  |   |\n";
        std::cout << "  O   |\n";
        std::cout << " /|\\  |\n";
        std::cout << " / \\  |\n";
        std::cout << "      |\n";
        std::cout << "========="  << std::endl;
        break;
    default:
        std::cout << "End" << std::endl;
    }
}    

