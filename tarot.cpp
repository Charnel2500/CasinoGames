#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> 

#include <sstream>

void welcomeTarot(){
    std::cout << "A tarot card will be drawn in a moment.\
    This card will determine your luck in the casino as well as in your \
    life outside of it. Only the first drawn card counts.\n\n \n";
    std::cout << "████████╗░█████╗░██████╗░░█████╗░████████╗ \n";
    std::cout << "╚══██╔══╝██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝ \n";
    std::cout << "░░░██║░░░███████║██████╔╝██║░░██║░░░██║░░░ \n";
    std::cout << "░░░██║░░░██╔══██║██╔══██╗██║░░██║░░░██║░░░ \n";
    std::cout << "░░░██║░░░██║░░██║██║░░██║╚█████╔╝░░░██║░░░ \n";
    std::cout << "░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░\n\n" << std::endl;
}

void readTarotCard(){
    sf::Music startMusic;
    if (!startMusic.openFromFile("music/tarot.wav")) {
        std::cerr << "Failed to load start music!" << std::endl;
    } else {
        startMusic.play();
        startMusic.setLoop(true);
    }
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
        std::cerr << "Failed to open the file!" << std::endl;
    }
    srand(time(NULL));
    int randomTarotCardIndex = rand() % 22;

    std::cout << "This is your card for today: \n" << tarotLines[randomTarotCardIndex] << std::endl;
    
        sf::RenderWindow window(sf::VideoMode(800, 600), "Tarot Card");

    // Pętla główna
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        std::stringstream imagePathStream;
        imagePathStream << "tarot_images/" << randomTarotCardIndex+1 << ".jpg";
        std::string imagePath = imagePathStream.str();
        sf::Texture texture;
        if (texture.loadFromFile(imagePath)) {
            sf::Sprite sprite(texture);
            window.clear();
            window.draw(sprite);
            window.display();
        } else {
            std::cout << "Can't load image!" << std::endl;
        }
    }
    startMusic.stop();
}
