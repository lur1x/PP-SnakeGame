#pragma once

#include <deque>

#include "direction.h"
#include "coordinate.h"
#include "consts.h"

class Snake
{
public:
    std::deque<Coordinate> body;
    Direction direction;

    Snake();

    void ChangeDir();

    void Move(bool& appleWasEaten);

    bool CheckPlayerWin();

    bool CheckCollisionWithSelf();

    bool CheckCollisionWithWall();
};
