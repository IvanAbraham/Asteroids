#pragma once
#include "menu.h"
#include "gameplay.h"
#include "tutorial.h"
#include "credits.h"

struct Mouse
{

	Vector2 hitBox;
	Vector2 position;

};

extern bool openGame;

void InitMenuScreen(Vector2 screenSize);
void UpdMenuScreen();
void DrwMenuScreen(Vector2 screenSize);

void InitGameScreen(Vector2 screenSize);
void UpdGameScreen(Vector2 screenSize);
void DrwGameScreen();

void InitCreditsScreen(Vector2 screenSize);
void UpdateCreditsScreen();
void DrwCreditsScreen();

void InitTutorialScreen(Vector2 screenSize);
void UpdateTuotiralScreen();
void DrwTutorialScreen();