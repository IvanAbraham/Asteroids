#pragma once
#include "ship.h"
#include "asteroids.h"
#include "gamestates.h"

	void InitializeGame(Vector2 screenSize);
	void InitGameButtons(Vector2 screenSize);
	void LoadGame();
	void ResetGame(Vector2 screenSize);
	void UpdateGame(Vector2 screenSize, Vector2 mousePos);
	void DrawGame(Vector2 screenSize);
	void CheckCollisions();
	bool BulletCollision(Asteroid& asteroid, Bullet& bullet);
	void ShipCollision(Ship& ship, Asteroid& asteroid);
	void UnloadGame();