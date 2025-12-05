#pragma once
#include "raylib.h"
#include "gamestates.h"
#include "interactions.h"
#include "menu.h" 

extern Texture2D creditsBackgroundTexture;
extern Texture2D creditsReturnButtonTexture;
extern Buttons creditsReturnButton;

void InitializeCredits(Vector2 screenSize);
GameScreen UpdateCredits(Vector2 mousePos);
void DrawCredits();
void LoadCreditsTextures();