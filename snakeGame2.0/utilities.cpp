#include "utilities.h"

#include <cstdlib>
#include <iostream>

void GameUtilities::PrintGameOver()
{
    std::cout << "Game Over!" << std::endl;
}

void GameUtilities::PrintGameWin() {
    std::cout << "You win!" << std::endl;
}

void Utilities::PrepareRandom() {
    srand(time(NULL));
}


