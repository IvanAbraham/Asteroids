#pragma once
#include "raylib.h"
#include "interactions.h"

struct Mouse
{

	Vector2 hitBox;
	Vector2 position;

};

enum GameScreen
{

	Menu = 0,
	Game,
	Credits

};

struct Buttons
{
	Vector2 size;
	Vector2 position;

};

extern GameScreen currentScreen;
extern bool openGame;


void InitMenu(int screenWidth, int screenHeight);
void UpdateMenu();
void DrawMenu();

void UpdateGamep(int screenWidth, int screenHeight);
void DrawGame(int screenWidth, int screenHeight);

void UpdateCredits(int screenWidth, int screenHeight);
void DrawCredcits(int screenWidth, int screenHeight);
