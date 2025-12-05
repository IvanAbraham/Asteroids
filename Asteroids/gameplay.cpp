#include "gameplay.h"

	bool isPlaying;
	bool gameOver;

	void InitializeGame(Vector2 screenSize)
	{
		InitShip(screenSize);
		InitAsteroids(screenSize);
		isPlaying = true;
		gameOver = false;
	}

	void UpdateGame(Vector2 screenSize, Vector2 mousePos)
	{
		/*	
		if (IsKeyPressed(KEY_ESCAPE))
		{
			isPlaying = false;
		}
		*/
		if (isPlaying)
		{
			UpdateShip(mousePos);
			UpdateBullets();
			UpdateAsteroids(screenSize);

			for (int i = 0; i < maxAsteroids; i++)
			{
				if (asteroids[i].isActive)
				{
					for (int j = 0; j < maxBullets; j++)
					{
						if (bullets[j].isActive)
						{
							Collision(asteroids[i], bullets[j]);
						}
					}

					if (CollisionCircleCircle(P1.position, P1.radius,
						asteroids[i].position, asteroids[i].radius))
					{
						asteroids[i].isActive = false;

						P1.lifes += -1;

						if (P1.lifes <= 0)
						{
							gameOver = true;
						}

					}
				}
			}

			if (gameOver)
			{
				isPlaying = false;
			}

		}

		if (gameOver)
		{
			
			currentScreen = Menu;

		}

	}

	void DrawGame()
	{
		ClearBackground(BLACK);

		DrawShip(P1);
		DrawBullets();
		DrawAsteroids();
	}

	void Collision(Asteroid& asteroid, Bullet& bullet)
	{
			if (CollisionCircleCircle(asteroid.position, asteroid.radius, bullet.position, bullet.radius))
			{
				asteroid.isActive = false;
				bullet.isActive = false;
			}
	}

