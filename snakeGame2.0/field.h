#pragma once

#include <vector>

#include "coordinate.h"
#include "consts.h"
#include "snake.h"

class SnakeField {
private:
    std::vector<std::vector<char>> fieldChars; 
    Coordinate apple;

public:
    SnakeField(); 

    void PlaceApple(Snake& snake);

    void DrawSnake(Snake& snake); 

    void Print();

    void clearScreen();

    void RandomizeApple();

    void DeleteSnakeFromField(Snake& snake); // переделать

    bool CheckEatApple(Snake& snake, bool& appleWasEaten); 

    Coordinate& GetApple();
};
