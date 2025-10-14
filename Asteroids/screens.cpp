#include "screens.h"

Buttons title = {};
Buttons startButton = {};
Buttons quitButton = {};

void InitMenu(int screenWidth, int screenHeight)
{

	title.size.x = screenWidth / 2;
	title.size.y = screenHeight / 15;
	title.position.x = screenWidth / 2 - (title.size.x / 2);
	title.position.y = screenHeight / 3 - (title.size.y / 2);

	startButton.size.x = screenWidth / 4;
	startButton.size.y = screenHeight / 20;
	startButton.position.x = screenWidth / 2 - (startButton.size.x / 2);
	startButton.position.y = title.position.y + title.size.y + 150;

	quitButton.size.x = screenWidth / 4;
	quitButton.size.y = screenHeight / 20;
	quitButton.position.x = screenWidth / 2 - (quitButton.size.x / 2);
	quitButton.position.y = startButton.position.y + quitButton.size.y + 100;

}

void UpdateMenu()
{
	DrawRectangleV(title.position, title.size, PINK);
	DrawRectangleV(startButton.position, startButton.size, BLUE);
	DrawRectangleV(quitButton.position, quitButton.size, RED);

}