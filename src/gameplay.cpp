#include "gameplay.h"

	bool isPlaying;
	bool gameOver;

	float invTimer = 5.0f;

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

					if (!P1.isHurt)
					{
						if (CollisionCircleCircle(P1.position, P1.radius, asteroids[i].position, asteroids[i].radius))
						{
							asteroids[i].isActive = false;

							P1.lifes += -1;

							P1.isHurt = true;

							if (P1.lifes <= 0)
							{
								gameOver = true;
							}
						}
					}
					else
					{
						invTimer -= GetFrameTime();
						if (invTimer <= 0)
						{
							P1.isHurt = false;
							invTimer = 2.0f;
						}
					}
				
				}
			}

			if (gameOver)
			{
				isPlaying = false;
			}

		}

		if (!isPlaying && !gameOver)
		{

		}

		if (gameOver)
		{
			currentScreen = Menu;
		}
	}

	void DrawGame()
	{
		ClearBackground(BLACK);
		DrawText(TextFormat("Lifes: %i", P1.lifes), 0, 0, 40, WHITE);
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

