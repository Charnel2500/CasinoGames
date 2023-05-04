#ifndef HANGMAN_H_INCLUDED
#define HANGMAN_H_INCLUDED
const int MAX_NUMBER_CATEGORIES = 3;
const int MAX_NAME_HANGMAN = 20;

extern std::string wordBase[MAX_NUMBER_CATEGORIES][MAX_NAME_HANGMAN];

std::string chooseCategoryDrawWord(std::string (&wordBase)[MAX_NUMBER_CATEGORIES][MAX_NAME_HANGMAN]);
void gameHangman(std::string (&wordBase)[MAX_NUMBER_CATEGORIES][MAX_NAME_HANGMAN]);
void drawHangman(int numWrongAnswers);
void hangman();

#endif // HANGMAN_H_INCLUDED
