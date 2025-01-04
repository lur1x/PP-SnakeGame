#include "snake.h"
#include <conio.h>

Snake::Snake() {
    body.push_back({ 2, 1 });
    body.push_back({ 1, 1 });
    direction = Direction::RIGHT;
}

void Snake::ChangeDir()
{
    switch (_getch())
    {
    case LEFT_KEY_CODE:
        if (direction != Direction::RIGHT)
        {
            direction = Direction::LEFT;
        }
        break;

    case RIGHT_KEY_CODE:
        if (direction != Direction::LEFT)
        {
            direction = Direction::RIGHT;
        }
        break;

    case UP_KEY_CODE:
        if (direction != Direction::DOWN)
        {
            direction = Direction::UP;
        }
        break;


    case DOWN_KEY_CODE:
        if (direction != Direction::UP)
        {
            direction = Direction::DOWN;
        }
        break;

    default:
        break;
    }
}

void Snake::Move(bool& appleWasEaten)
{
    Coordinate newSnakeCell = body[body.size() - 1];
    Coordinate snakeHead = body[0];

    newSnakeCell.x = snakeHead.x;
    newSnakeCell.y = snakeHead.y;

    if (direction == Direction::LEFT)
    {
        newSnakeCell.x = newSnakeCell.x - 1;
    }
    else if (direction == Direction::RIGHT)
    {
        newSnakeCell.x = newSnakeCell.x + 1;
    }
    else if (direction == Direction::DOWN)
    {
        newSnakeCell.y = newSnakeCell.y + 1;
    }
    else if (direction == Direction::UP)
    {
        newSnakeCell.y = newSnakeCell.y - 1;
    }

    if (appleWasEaten)
    {
        body.push_front(newSnakeCell);
        appleWasEaten = false;
    }
    else
    {
        body.pop_back();
        body.push_front(newSnakeCell);
    }
}

bool Snake::CheckPlayerWin() {
    return body.size() == (ROW_COUNT - 2) * (COLUMN_COUNT - 2);
}

bool Snake::CheckCollisionWithSelf() {
    Coordinate snakeHead = body[0];
    for (auto i = 1; i < body.size(); i++)
    {
        if (snakeHead.x == body[i].x && snakeHead.y == body[i].y)
        {
            return true;
        }
    }
    return false;
}

bool Snake::CheckCollisionWithWall() {
    if (body[0].x == 0 || body[0].x == COLUMN_COUNT - 1)
    {
        return true;
    }
    else if (body[0].y == 0 || body[0].y == ROW_COUNT - 1)
    {
        return true;
    }
    return false;
}
