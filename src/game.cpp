#include "game.h"

void ExecuteGame()
{
	openGame = true;

	Vector2 screenSize = { 1280, 900 };
	InitWindow(static_cast<int>(screenSize.x), static_cast<int>(screenSize.y), "Asteroids");
	
	InitMenuScreen(screenSize);
	InitGameScreen(screenSize);
	InitCreditsScreen(screenSize);
	InitTutorialScreen(screenSize);

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

			UpdateCreditsScreen();

			break;

		case Tutorial:

			UpdateTuotiralScreen();

			break;

	}
	

}

void Draw(Vector2 screenSize)
{
	switch (currentScreen)
	{

		case Menu:

			DrawMenu(screenSize);

			break;

		case Game:

			DrwGameScreen();

			break;

		case Credits:

			DrwCreditsScreen();

			break;

		case Tutorial:

			DrwTutorialScreen();

			break;
	}
	

}