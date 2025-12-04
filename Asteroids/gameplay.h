#pragma once
#include "ship.h"
#include "asteroids.h"

	void InitializeGame(Vector2 screenSize);
	void UpdateGame(Vector2 screenSize, Vector2 mousePos);
	void DrawGame(Vector2 screenSize);
	void Collision(Asteroid& asteroid, Bullet& bullet);
