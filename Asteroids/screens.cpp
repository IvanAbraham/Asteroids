#include "screens.h"


Buttons title = {};
Buttons startButton = {};
Buttons quitButton = {};
Vector2 mousePos;

GameScreen currentScreen = Menu;
bool openGame = true;

void InitMenu(int screenWidth, int screenHeight)
{

	title.size.x = screenWidth / 1.5;
	title.size.y = screenHeight / 5;
	title.position.x = screenWidth / 2 - (title.size.x / 2);
	title.position.y = screenHeight / 5 - (title.size.y / 2);

	startButton.size.x = screenWidth / 4;
	startButton.size.y = screenHeight / 20;
	startButton.position.x = screenWidth / 2 - (startButton.size.x / 2);
	startButton.position.y = title.position.y + title.size.y + 120;

	quitButton.size.x = screenWidth / 4;
	quitButton.size.y = screenHeight / 20;
	quitButton.position.x = screenWidth / 2 - (quitButton.size.x / 2);
	quitButton.position.y = startButton.position.y + quitButton.size.y + 70;

}

void UpdateMenu()
{
	 mousePos = GetMousePosition();

	 if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	 {

		 if (CollisionPointRec(mousePos, startButton.position, startButton.size))
		 {

			 currentScreen = Game;

		 }

		 if (CollisionPointRec(mousePos, quitButton.position, quitButton.size))
		 {


			 openGame = false;


		 }

	 }

	 

}

void DrawMenu()
{

	DrawRectangleV(title.position, title.size, PINK);
	DrawRectangleV(startButton.position, startButton.size, BLUE);
	DrawRectangleV(quitButton.position, quitButton.size, RED);

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