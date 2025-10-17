#pragma once
#include "raylib.h"
#include "gamestates.h"
#include "interactions.h"

struct Buttons
{
	Vector2 size;
	Vector2 position;

};

void InitializeMenu(Vector2 screenSize);
GameScreen UpdateMenu(Vector2 mousePos);
void DrawMenu();