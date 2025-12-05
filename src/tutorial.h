#pragma once
#include "raylib.h"
#include "gamestates.h"
#include "interactions.h"
#include "menu.h" 

extern Texture2D tutorialBackgroundTexture;
extern Texture2D returnButtonTexture;
extern Buttons returnButton;

void InitializeTutorial(Vector2 screenSize);
GameScreen UpdateTutorial(Vector2 mousePos);
void DrawTutorial();
void LoadTutorialTextures();