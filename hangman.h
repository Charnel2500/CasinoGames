#ifndef HANGMAN_H_INCLUDED
#define HANGMAN_H_INCLUDED

#include <vector> 

const int MAX_NUMBER_CATEGORIES = 3;

extern std::vector<std::string> wordBase[MAX_NUMBER_CATEGORIES];  

std::string chooseCategoryDrawWord(std::vector<std::string> (&wordBase)[MAX_NUMBER_CATEGORIES]); 
int gameHangman(std::vector<std::string> (&wordBase)[MAX_NUMBER_CATEGORIES]);
void drawHangman(int numWrongAnswers);
void welcomeHangman();

#endif
