#include "game.h"

void ExecuteGame()
{

	Vector2 screenSize = { 1280, 720 };
	InitWindow(screenSize.x, screenSize.y, "Asteroids");
	
	InitMenu(screenSize.x, screenSize.y);

	while (!WindowShouldClose())
	{

		BeginDrawing();

		Update(screenSize);

		EndDrawing();

	}
}

void Update(Vector2 screenSize)
{

	UpdateMenu();

}