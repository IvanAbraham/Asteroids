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

void InitGame(Vector2 screenSize)
{



}

void UpdateGame()
{



}

void DrawGame()
{



}