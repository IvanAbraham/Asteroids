#include "gameplay.h"

	bool isPlaying;
	bool gameOver;

	float invTimer;;

	int score;

	void InitializeGame(Vector2 screenSize)
	{
		InitShip(screenSize);
		InitAsteroids(screenSize);
		isPlaying = true;
		gameOver = false;

		score = 0;
		invTimer = 5.0f;
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

			if (InScreenCheck(P1.position, P1.radius, screenSize))
			{
				if (P1.position.x + P1.radius < 0)
				{
					P1.position.x = screenSize.x - P1.radius;
				}
				else if (P1.position.x - P1.radius > screenSize.x)
				{
					P1.position.x = 0;
				}
				
				if (P1.position.y > screenSize.y + P1.radius)
				{
					P1.position.y = 0;
				}
				else if (P1.position.y + P1.radius < 0)
				{
					P1.position.y = screenSize.y - P1.radius;
				}
			}

			//Collisions between objects
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
		DrawText(TextFormat("Score: %i", score), 900, 0, 40, WHITE);
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

				score += 10;
			}
	}

