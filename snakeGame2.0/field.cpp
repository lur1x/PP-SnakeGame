#include "field.h"

SnakeField::SnakeField() :
    fieldChars(ROW_COUNT, std::vector<char>(COLUMN_COUNT, ' '))
{
    for (int i = 0; i < COLUMN_COUNT; i++)
    {
        fieldChars[0][i] = BORDER_SYMBOL;
        fieldChars[ROW_COUNT - 1][i] = BORDER_SYMBOL;
    }

    for (int i = 1; i < ROW_COUNT - 1; i++)
    {
        fieldChars[i][0] = BORDER_SYMBOL;
        fieldChars[i][COLUMN_COUNT - 1] = BORDER_SYMBOL;
    }
}

void SnakeField::RandomizeApple() {
    apple.x = rand() % (COLUMN_COUNT - 2) + 1;
    apple.y = rand() % (ROW_COUNT - 2) + 1;
}

void SnakeField::PlaceApple(Snake& snake)
{
    RandomizeApple();

    for (auto i = 0; i < snake.body.size(); i++)
    {
        if (snake.body[i].x == apple.x && snake.body[i].y == apple.y)
        {
            RandomizeApple();

            i = 0;
        }
    }
    fieldChars[apple.y][apple.x] = APPLE_SYMBOL;
}


void SnakeField::DrawSnake(Snake& snake)
{
    Coordinate snakeHead = snake.body.at(0);
    fieldChars[snakeHead.y][snakeHead.x] = SNAKE_HEAD_SYMBOL;

    for (size_t i = 1; i < snake.body.size(); i++)
    {
        fieldChars[snake.body[i].y][snake.body[i].x] = SNAKE_BODY_SYMBOL;
    }
}

void SnakeField::clearScreen()
{
    system("cls");
}

void SnakeField::Print()
{
    clearScreen();
    for (const auto row : fieldChars)
    {
        for (const auto cell : row) {
            std::cout << cell;
        }
        std::cout << "\n";
    }
}

void SnakeField::DeleteSnakeFromField(Snake& snake)
{
    for (auto i = 0; i < snake.body.size(); i++) //выбрать единный стиль
    {
        fieldChars[snake.body[i].y][snake.body[i].x] = ' ';
    }
}

bool SnakeField::CheckEatApple(Snake& snake, bool& appleWasEaten) {
    Coordinate snakeHead = snake.body.at(0);
    if (snakeHead.x == apple.x && snakeHead.y == apple.y)
    {
        appleWasEaten = true;
        return true;
    }
    return false;
}

Coordinate& SnakeField::GetApple() {
    return apple;
}
