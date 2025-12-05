#include "screens.h"

Vector2 mousePos;

GameScreen currentScreen = Menu;
bool openGame = true;

void InitMenuScreen(Vector2 screenSize)
{
	LoadMenuTextures();
	LoadTutorialTextures();
	LoadCreditsTextures();
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

void DrwMenuScreen(Vector2 screenSize)
{

	DrawMenu(screenSize);

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

void InitCreditsScreen(Vector2 screenSize)
{
	InitializeCredits(screenSize);
}

void UpdateCreditsScreen()
{

	mousePos = GetMousePosition();

	currentScreen = UpdateCredits(mousePos);

}

void DrwCreditsScreen()
{

	DrawCredits();

}

void InitTutorialScreen(Vector2 screenSize)
{

	InitializeTutorial(screenSize);

}

void UpdateTuotiralScreen()
{

	mousePos = GetMousePosition();

	currentScreen = UpdateTutorial(mousePos);

}

void DrwTutorialScreen()
{

	DrawTutorial();

}