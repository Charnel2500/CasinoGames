#ifndef PLAYER_H
#define PLAYER_H

#include <string>

enum class PlayerType {
    MainPlayer,
    Opponent
};

struct Player {
    const std::string name;
    const int age;
    const PlayerType type;
    void printInfo();
};

#endif

