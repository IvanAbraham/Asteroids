#include "credits.h"
#include "raylib.h"

Texture2D creditsBackgroundTexture;
Texture2D creditsReturnButtonTexture;
Buttons creditsReturnButton = {};

void LoadCreditsTextures()
{
    creditsBackgroundTexture = LoadTexture("../res/sprites/Credits/Credits.png");
    creditsReturnButtonTexture = LoadTexture("../res/sprites/Buttons/Back.png");
}

void InitializeCredits(Vector2 screenSize)
{
    creditsReturnButton.size.x = screenSize.x / 5.0f;
    creditsReturnButton.size.y = screenSize.y / 15.0f;
    creditsReturnButton.position.x = screenSize.x - creditsReturnButton.size.x - 50;
    creditsReturnButton.position.y = screenSize.y - creditsReturnButton.size.y - 50;
}

GameScreen UpdateCredits(Vector2 mousePos)
{
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        if (CollisionPointRec(mousePos, creditsReturnButton.position, creditsReturnButton.size))
        {
            return Menu; 
        }
    }

    return Credits; 
}

void DrawCredits()
{

    ClearBackground(BLACK);

    Rectangle sourceBG = { 0, 0, static_cast<float>(creditsBackgroundTexture.width), static_cast<float>(creditsBackgroundTexture.height) };
    Rectangle destBG = { 0, 0, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) };
    DrawTexturePro(creditsBackgroundTexture, sourceBG, destBG, { 0, 0 }, 0.0f, WHITE);

    Rectangle sourceReturn = { 0, 0, static_cast<float>(creditsReturnButtonTexture.width), static_cast<float>(creditsReturnButtonTexture.height) };
    Rectangle destReturn = { creditsReturnButton.position.x, creditsReturnButton.position.y,
                            creditsReturnButton.size.x, creditsReturnButton.size.y };
    DrawTexturePro(creditsReturnButtonTexture, sourceReturn, destReturn, { 0, 0 }, 0.0f, WHITE);

}