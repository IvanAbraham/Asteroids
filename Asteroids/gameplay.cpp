#include "gameplay.h"



void InitializeGame(Vector2 screenSize)
{

	InitShip(screenSize);

}

void UpdateGame(Vector2 screenSize, Vector2 mousePos)
{

	UpdateShip(mousePos);
	UpdateBullets();

}

void DrawGame(Vector2 screenSize)
{

	DrawShip(P1);
	DrawBullets();

	ClearBackground(BLACK);
}