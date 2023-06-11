#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>

void welcomeTarot(){
    std::cout << "A tarot card will be drawn in a moment.\
    This card will determine your luck in the casino as well as in your \
    life outside of it. Only the first drawn card counts.\n\n" << std::endl;
    std::cout << "████████╗░█████╗░██████╗░░█████╗░████████╗" << std::endl;
    std::cout << "╚══██╔══╝██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝" << std::endl;
    std::cout << "░░░██║░░░███████║██████╔╝██║░░██║░░░██║░░░" << std::endl;
    std::cout << "░░░██║░░░██╔══██║██╔══██╗██║░░██║░░░██║░░░" << std::endl;
    std::cout << "░░░██║░░░██║░░██║██║░░██║╚█████╔╝░░░██║░░░" << std::endl;
    std::cout << "░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░\n\n" << std::endl;
}

void readTarotCard(){
    welcomeTarot();
    std::vector<std::string> tarotLines;
    std::string line;
    std::ifstream inputFile("tarot.txt");
    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            tarotLines.push_back(line);
        }
        inputFile.close();
    }
    else {
        std::cerr << "Nie udało się otworzyć pliku!" << std::endl;
    }
    srand(time(NULL));
    int randomTarotCardIndex = rand() % 22;

    std::cout << "This is your card for today: \n" << tarotLines[randomTarotCardIndex] << std::endl;
}
