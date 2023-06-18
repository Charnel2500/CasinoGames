#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <string>
using namespace std;
class Player
{
private:
    string name;
    int age;
public:
    Player(string, int);
    void setValues(string name, int age);
    string getName();
    int getAge();
    void printInfo(string name, int age);
};


#endif // PLAYER_H_INCLUDED
