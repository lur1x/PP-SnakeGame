#include <conio.h>
#include <cstdlib>
#include <Windows.h>

#include "utilities.h"
#include "snake.h"
#include "field.h" 



int main()
{
    Utilities::PrepareRandom();

    bool appleWasEaten = false;
    Snake snake;

    SnakeField field;

    field.DrawSnake(snake);
    field.PlaceApple(snake);

    field.Print();

    while (true)
    {
        Sleep(GAME_LOOP_SLEEP_MS);

        if (_kbhit())
        {
            snake.ChangeDir();
        }

        field.DeleteSnakeFromField(snake);
        snake.Move(appleWasEaten);

        if (snake.CheckCollisionWithWall() || snake.CheckCollisionWithSelf())
        {
            GameUtilities::PrintGameOver();
            break;
        }
        if (snake.CheckPlayerWin())
        {
            GameUtilities::PrintGameWin();
            break;
        }

        if (field.CheckEatApple(snake, appleWasEaten))
        {
            field.PlaceApple(snake);
        }

        field.DrawSnake(snake);
        field.Print();
    }

    return 0;
}
