#include "screens.h"

Vector2 mousePos;

GameScreen currentScreen = Menu;
bool openGame = true;

void InitMenuScreen(Vector2 screenSize)
{

	InitializeMenu(screenSize);

}

void UpdMenuScreen()
{
	 mousePos = GetMousePosition();	 

	 currentScreen = UpdateMenu(mousePos);

	 if (currentScreen == Quit)
	 {

		 openGame = false;

	 }

}

void DrwMenuScreen()
{

	DrawMenu();

}

void InitGameScreen(Vector2 screenSize)
{

	InitializeGame(screenSize);

}

void UpdGameScreen(Vector2 screenSize)
{

	mousePos = GetMousePosition();

	UpdateGame(screenSize, mousePos);

}

void DrwGameScreen()
{

	DrawGame();

}