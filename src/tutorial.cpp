#include "tutorial.h"
#include "raylib.h"

Texture2D tutorialBackgroundTexture;
Texture2D returnButtonTexture;
Buttons returnButton = {};

void LoadTutorialTextures()
{
    tutorialBackgroundTexture = LoadTexture("../res/sprites/Tutorial/Tutorial.png");
    returnButtonTexture = LoadTexture("../res/sprites/Buttons/Back.png");
}

void InitializeTutorial(Vector2 screenSize)
{
    returnButton.size.x = screenSize.x / 5.0f;
    returnButton.size.y = screenSize.y / 15.0f;

    returnButton.position.x = screenSize.x - returnButton.size.x - 50;
    returnButton.position.y = screenSize.y - returnButton.size.y - 50;
}

GameScreen UpdateTutorial(Vector2 mousePos)
{
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        if (CollisionPointRec(mousePos, returnButton.position, returnButton.size))
        {
            return Menu; 
        }
    }
    return Tutorial; 
}

void DrawTutorial()
{
    ClearBackground(BLACK);

    Rectangle sourceBG = { 0, 0, (float)tutorialBackgroundTexture.width, (float)tutorialBackgroundTexture.height };
    Rectangle destBG = { 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() };
    DrawTexturePro(tutorialBackgroundTexture, sourceBG, destBG, { 0, 0 }, 0.0f, WHITE);

    Rectangle sourceReturn = { 0, 0, (float)returnButtonTexture.width, (float)returnButtonTexture.height };
    Rectangle destReturn = { returnButton.position.x, returnButton.position.y,
                            returnButton.size.x, returnButton.size.y };
    DrawTexturePro(returnButtonTexture, sourceReturn, destReturn, { 0, 0 }, 0.0f, WHITE);
}