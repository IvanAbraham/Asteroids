#pragma once
#include "menu.h"
#include "gamestates.h"

struct Mouse
{

	Vector2 hitBox;
	Vector2 position;

};

extern bool openGame;

void InitMenuScreen(Vector2 screenSize);
void UpdMenuScreen();
void DrwMenuScreen();

void UpdateGamep(int screenWidth, int screenHeight);
void DrawGame(int screenWidth, int screenHeight);

void UpdateCredits(int screenWidth, int screenHeight);
void DrawCredcits(int screenWidth, int screenHeight);
