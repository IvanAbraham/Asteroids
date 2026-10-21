#include "gameplay.h"

	bool isPlaying;
	bool gameOver;

	int score;

	Sound shoot;
	Sound engines;
	Sound death;
	Sound explotion;

	Texture2D paused;

	void InitializeGame(Vector2 screenSize)
	{
		InitShip(screenSize);
		LoadShipTexture();
		InitAsteroids(screenSize);
		LoadAsteroidsTexture();

		paused = LoadTexture(".. /res/Sprites/Pause&Gover/Paused.png");

		shoot = LoadSound("../res/sfx/Shoot.wav");
		engines = LoadSound("../res/sfx/Engines.wav");
		death = LoadSound("../res/sfx/Death.wav");
		explotion = LoadSound("../res/sfx/AsteroidBoom.wav");

		isPlaying = true;
		gameOver = false;
		score = 0;
	}

	void UpdateGame(Vector2 screenSize, Vector2 mousePos)
	{
		
		if (IsKeyReleased(KEY_ESCAPE))
		{
			isPlaying = false;
		}
		
		if (isPlaying)
		{
			UpdateShip(mousePos);
			UpdateBullets();
			UpdateAsteroids(screenSize);

			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySound(shoot);
			}

			if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
			{
				PlaySound(engines);
			}

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
					//Bullet collisions
					for (int j = 0; j < maxBullets; j++)
					{
						if (bullets[j].isActive)
						{
							if (BulletCollision(asteroids[i], bullets[j]))
								break;
						}
					}
					//Ship collisions
					if (!P1.isHurt && asteroids[i].isActive)
					{
						ShipCollision(P1, asteroids[i]);
					}
				
				}
			}

			if (gameOver)
			{
				isPlaying = false;

			}

		}
		else if (!isPlaying && !gameOver)
		{

			if (IsKeyPressed(KEY_ESCAPE))
			{
				currentScreen = Menu;
			}

			if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
			{
				isPlaying = true;
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
		DrawText(TextFormat("Lifes: %i", P1.lifes), 0, 0, 40, WHITE);
		DrawText(TextFormat("Score: %i", score), 900, 0, 40, WHITE);
		DrawShip();
		DrawBullets();
		DrawAsteroids();
	}

	bool BulletCollision(Asteroid& asteroid, Bullet& bullet)
	{
			if (CollisionCircleCircle(asteroid.position, asteroid.radius, bullet.position, bullet.radius))
			{
				SplitAsteroid(asteroid);
				bullet.isActive = false;
				score += 10;
				PlaySound(explotion);		

				return true;
			}
			return false;
	}

	void ShipCollision(Ship& ship, Asteroid& asteroid)
	{
		if (CollisionCircleCircle(ship.position, ship.radius, asteroid.position, asteroid.radius))
		{
			asteroid.isActive = false;

			ship.lifes += -1;

			ship.isHurt = true;
			ship.invTimer = invDuration;
			PlaySound(death);

			if (ship.lifes <= 0)
			{
				gameOver = true;
			}
		}
	}