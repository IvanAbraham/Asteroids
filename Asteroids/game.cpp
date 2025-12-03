#include "game.h"

void ExecuteGame()
{

	openGame = true;

	Vector2 screenSize = { 1280, 900 };
	InitWindow(screenSize.x, screenSize.y, "Asteroids");
	
	InitMenuScreen(screenSize);
	InitGameScreen(screenSize);


	while (openGame)
	{

		Update(screenSize);

		BeginDrawing();

		Draw(screenSize);

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

			UpdGameScreen(screenSize);

			break;

		case Credits:

			break;

	}
	

}

void Draw(Vector2 screenSize)
{
	switch (currentScreen)
	{

		case Menu:

			DrwMenuScreen();

			break;

		case Game:

			DrwGameScreen(screenSize);

			break;
	}
	

}