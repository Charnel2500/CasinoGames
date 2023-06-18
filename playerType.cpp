#include "playerType.h"
#include <iostream>

void Player::printInfo() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Type: " << static_cast<int>(type) << std::endl;
}
