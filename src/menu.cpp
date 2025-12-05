#include "menu.h"

Buttons title = {};
Buttons startButton = {};
Buttons tutorialButton = {};
Buttons creditsButton = {};
Buttons quitButton = {};

Texture2D menuTexture;
Texture2D startTexture;
Texture2D tutorialTexture;
Texture2D creditsTexture;
Texture2D quitTexture;

void InitializeMenu(Vector2 screenSize)
{

    title.size.x = screenSize.x / 1.5f;
    title.size.y = screenSize.y / 5.0f;
    title.position.x = screenSize.x / 2.0f - (title.size.x / 2.0f);
    title.position.y = screenSize.y / 5.0f - (title.size.y / 2.0f);

    startButton.size.x = screenSize.x / 3.5f;
    startButton.size.y = screenSize.y / 15.0f;
    startButton.position.x = screenSize.x / 2.0f - (startButton.size.x / 2.0f);
    startButton.position.y = title.position.y + title.size.y + 120;

    tutorialButton.size.x = screenSize.x / 3.5f;
    tutorialButton.size.y = screenSize.y / 15.0f;
    tutorialButton.position.x = screenSize.x / 2.0f - (tutorialButton.size.x / 2.0f);
    tutorialButton.position.y = startButton.position.y + tutorialButton.size.y + 70;

    creditsButton.size.x = screenSize.x / 3.5f;
    creditsButton.size.y = screenSize.y / 15.0f;
    creditsButton.position.x = screenSize.x / 2.0f - (creditsButton.size.x / 2.0f);
    creditsButton.position.y = tutorialButton.position.y + creditsButton.size.y + 70;

    quitButton.size.x = screenSize.x / 3.5f;
    quitButton.size.y = screenSize.y / 15.0f;
    quitButton.position.x = screenSize.x / 2.0f - (quitButton.size.x / 2.0f);
    quitButton.position.y = creditsButton.position.y + quitButton.size.y + 70;

}

GameScreen UpdateMenu(Vector2 mousePos)
{

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {

        if (CollisionPointRec(mousePos, startButton.position, startButton.size))
        {

            return Game;

        }

        if (CollisionPointRec(mousePos, tutorialButton.position, tutorialButton.size))
        {

            return Tutorial;

        }

        if (CollisionPointRec(mousePos, creditsButton.position, creditsButton.size))
        {

            return Credits;

        }

        if (CollisionPointRec(mousePos, quitButton.position, quitButton.size))
        {

            return Quit;

        }

    }

    return Menu;

}

void DrawMenu(Vector2 screenSize)
{
    Rectangle sourceMenu = { 0, 0, (float)menuTexture.width, (float)menuTexture.height };
    Rectangle destMenu = { 0, 0, screenSize.x, screenSize.y};
    DrawTexturePro(menuTexture, sourceMenu, destMenu, { 0, 0 }, 0.0f, WHITE);

    Rectangle sourceStart = { 0, 0, (float)startTexture.width, (float)startTexture.height };
    Rectangle destStart = { startButton.position.x, startButton.position.y, startButton.size.x, startButton.size.y };
    DrawTexturePro(startTexture, sourceStart, destStart, { 0, 0 }, 0.0f, WHITE);

    Rectangle sourceTutorial = { 0, 0, (float)tutorialTexture.width, (float)tutorialTexture.height };
    Rectangle destTutorial = { tutorialButton.position.x, tutorialButton.position.y, tutorialButton.size.x, tutorialButton.size.y };
    DrawTexturePro(tutorialTexture, sourceTutorial, destTutorial, { 0, 0 }, 0.0f, WHITE);

    Rectangle sourceCredits = { 0, 0, (float)creditsTexture.width, (float)creditsTexture.height };
    Rectangle destCredits = { creditsButton.position.x, creditsButton.position.y, creditsButton.size.x, creditsButton.size.y };
    DrawTexturePro(creditsTexture, sourceCredits, destCredits, { 0, 0 }, 0.0f, WHITE);

    Rectangle sourceQuit = { 0, 0, (float)quitTexture.width, (float)quitTexture.height };
    Rectangle destQuit = { quitButton.position.x, quitButton.position.y, quitButton.size.x, quitButton.size.y };
    DrawTexturePro(quitTexture, sourceQuit, destQuit, { 0, 0 }, 0.0f, WHITE);

}

void LoadMenuTextures()
{

    menuTexture = LoadTexture("../res/sprites/Menu/Menus.png");
    startTexture = LoadTexture("../res/sprites/Buttons/Play.png");
    tutorialTexture = LoadTexture("../res/sprites/Buttons/Tutorial.png");
    creditsTexture = LoadTexture("../res/sprites/Buttons/Credits.png");
    quitTexture = LoadTexture("../res/sprites/Buttons/Quit.png");

}