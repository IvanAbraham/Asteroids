#pragma once
#include "gamestates.h"
#include "interactions.h"

void InitializeMenu(Vector2 screenSize);
GameScreen UpdateMenu(Vector2 mousePos);
void DrawMenu(Vector2 screenSize);
void LoadMenuTextures();
void UnloadMenuTextures();