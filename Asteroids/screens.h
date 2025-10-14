#pragma once
#include "raylib.h"

enum GameScreen
{

	Menu = 0,
	Gameplay,
	Credits

};

struct Buttons
{
	Vector2 size;
	Vector2 position;

};

extern GameScreen currentScreen;

void InitMenu(int screenWidth, int screenHeight);
void UpdateMenu();

void DrawMenu();

void UpdateGamep(int screenWidth, int screenHeight);
void DrawGame(int screenWidth, int screenHeight);

void UpdateCredits(int screenWidth, int screenHeight);
void DrawCredcits(int screenWidth, int screenHeight);

