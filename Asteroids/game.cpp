#include "game.h"

void ExecuteGame()
{

	openGame = true;

	Vector2 screenSize = { 1280, 720 };
	InitWindow(screenSize.x, screenSize.y, "Asteroids");
	InitMenu(screenSize.x, screenSize.y);

	while (openGame)
	{

		Update(screenSize);

		BeginDrawing();

		Draw();

		EndDrawing();

	}
}

void Update(Vector2 screenSize)
{

	UpdateMenu();

}

void Draw()
{

	DrawMenu();

}