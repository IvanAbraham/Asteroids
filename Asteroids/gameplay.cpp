#include "gameplay.h"



void InitializeGame(Vector2 screenSize)
{

	InitShip(screenSize);
	InitAsteroids(screenSize);

}

void UpdateGame(Vector2 screenSize, Vector2 mousePos)
{

	UpdateShip(mousePos);
	UpdateBullets();
	UpdateAsteroids();

}

void DrawGame(Vector2 screenSize)
{

	DrawShip(P1);
	DrawBullets();
	DrawAsteroids();

	ClearBackground(BLACK);
}