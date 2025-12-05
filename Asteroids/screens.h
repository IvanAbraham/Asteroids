#pragma once
#include "menu.h"
#include "gameplay.h"

struct Mouse
{

	Vector2 hitBox;
	Vector2 position;

};

extern bool openGame;

void InitMenuScreen(Vector2 screenSize);
void UpdMenuScreen();
void DrwMenuScreen();

void InitGameScreen(Vector2 screenSize);
void UpdGameScreen(Vector2 screenSize);
void DrwGameScreen();

void UpdateCredits();
void DrawCredcits();
