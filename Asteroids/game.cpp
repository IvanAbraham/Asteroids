#include "game.h"

void ExecuteGame()
{

	openGame = true;

	Vector2 screenSize = { 1280, 720 };
	InitWindow(screenSize.x, screenSize.y, "Asteroids");
	
	InitMenuScreen(screenSize);

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
	switch (currentScreen)
	{

		case Menu:	
			
			UpdMenuScreen();

			break;

		case Game:

			break;

		case Credits:

			break;

	}
	

}

void Draw()
{

	DrwMenuScreen();

}