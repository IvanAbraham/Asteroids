#include "menu.h"

Buttons title = {};
Buttons startButton = {};
Buttons quitButton = {};

void InitializeMenu(Vector2 screenSize)
{

    title.size.x = screenSize.x / 1.5f;
    title.size.y = screenSize.y / 5.0f;
    title.position.x = screenSize.x / 2.0f - (title.size.x / 2.0f);
    title.position.y = screenSize.y / 5.0f - (title.size.y / 2.0f);

    startButton.size.x = screenSize.x / 4.0f;
    startButton.size.y = screenSize.y / 20.0f;
    startButton.position.x = screenSize.x / 2.0f - (startButton.size.x / 2.0f);
    startButton.position.y = title.position.y + title.size.y + 120;

    quitButton.size.x = screenSize.x / 4.0f;
    quitButton.size.y = screenSize.y / 20.0f;
    quitButton.position.x = screenSize.x / 2.0f - (quitButton.size.x / 2.0f);
    quitButton.position.y = startButton.position.y + quitButton.size.y + 70;

}

GameScreen UpdateMenu(Vector2 mousePos)
{

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {

        if (CollisionPointRec(mousePos, startButton.position, startButton.size))
        {

            return Game;

        }

        if (CollisionPointRec(mousePos, quitButton.position, quitButton.size))
        {

            return Quit;

        }

    }

}

void DrawMenu()
{

    DrawRectangleV(title.position, title.size, PINK);
    DrawRectangleV(startButton.position, startButton.size, BLUE);
    DrawRectangleV(quitButton.position, quitButton.size, RED);

}