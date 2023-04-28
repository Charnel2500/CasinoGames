#include "player.h"
#include <iostream>
#include <string>
Player::Player(string name, int age) {
    this->name = name;
    this->age = age;
}
Player::~Player()
{

}

void Player::setValues(string n, int years)
{
    this -> name = n;
    this -> age = years;
}

string Player::getName(){return name;}
int Player::getAge(){return age;};

void Player::printInfo(string name, int age)
{
    cout << "The name of the player is: " << name << endl;
    cout << "The age of the player is: " << age << endl;
}
