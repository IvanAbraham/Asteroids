#pragma once
#include "ship.h"
#include "asteroids.h"
#include "gamestates.h"

	void InitializeGame(Vector2 screenSize);
	void UpdateGame(Vector2 screenSize, Vector2 mousePos);
	void DrawGame();
	void Collision(Asteroid& asteroid, Bullet& bullet);
