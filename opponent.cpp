#include "opponent.h"
#include <iostream>
#include <string>
Opponent::Opponent(string name, int age) {
    this->name = name;
    this->age = age;
}

void Opponent::setValues(string n, int years)
{
    this -> name = n;
    this -> age = years;
}

string Opponent::getName(){return name;}
int Opponent::getAge(){return age;};

void Opponent::printInfo(string name, int age)
{
    cout << "The name of the opponent is: " << name << endl;
    cout << "The age of the opponent is: " << age << endl;
}
