#include "gameplay.h"

	bool isPlaying;
	bool gameOver;

	int score;

	Sound shoot;
	Sound engines;
	Sound death;
	Sound explotion;

	Texture2D paused;
	Texture2D deathScreen;
	Texture2D resumeTexture;
	Texture2D menuButtonTexture;

	Buttons pauseButton;
	Buttons resumeButton;
	Buttons menuButton;

	void InitializeGame(Vector2 screenSize)
	{
		LoadGame();
		InitGameButtons(screenSize);
		ResetGame(screenSize);
	}

	void InitGameButtons(Vector2 screenSize)
	{
		float PSize = static_cast<float>(MeasureText("P", 40));
		Vector2 PausePosition = { screenSize.x - PSize - 10, 10 };

		menuButton.size = { screenSize.x / 3.5f, screenSize.y / 15.0f };
		menuButton.position = { screenSize.x / 2 - menuButton.size.x / 2, screenSize.y / 2 + menuButton.size.y / 2 };
		resumeButton.size = { screenSize.x / 3.5f, screenSize.y / 15.0f };
		resumeButton.position = { screenSize.x / 2 - resumeButton.size.x / 2, menuButton.position.y - menuButton.size.y - 10};
		pauseButton.position = { PausePosition };
		pauseButton.size = { PSize, PSize };

	}

	void ResetGame(Vector2 screenSize)
	{
		isPlaying = true;
		gameOver = false;
		score = 0;

		InitShip(screenSize);
		InitAsteroids(screenSize);
	}

	void LoadGame()
	{
		paused = LoadTexture("res/sprites/Pause&Gover/Paused.png");
		deathScreen = LoadTexture("res/sprites/Pause&Gover/GameOver.png");
		resumeTexture = LoadTexture("res/sprites/Buttons/Resume.png");
		menuButtonTexture = LoadTexture("res/sprites/Buttons/Menu.png");
		shoot = LoadSound("res/sfx/Shoot.wav");
		engines = LoadSound("res/sfx/Engines.wav");
		death = LoadSound("res/sfx/Death.wav");
		explotion = LoadSound("res/sfx/AsteroidBoom.wav");
	
		LoadShipTexture();
		LoadAsteroidsTexture();
	}

	void UnloadGame()	
	{
		UnloadShipTexture();
		UnloadAsteroidsTexture();
		UnloadTexture(paused);
		UnloadTexture(menuButtonTexture);
		UnloadTexture(resumeTexture);
		UnloadTexture(deathScreen);
		UnloadSound(shoot);
		UnloadSound(engines);
		UnloadSound(death);
		UnloadSound(explotion);
	}

	void UpdateGame(Vector2 screenSize, Vector2 mousePos)
	{
		//Pause
		if (IsKeyReleased(KEY_ESCAPE) && !gameOver)
		{
			isPlaying = !isPlaying;
		}
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CollisionPointRec(mousePos, pauseButton.position, pauseButton.size))
		{
			isPlaying = false;
		}

		if (isPlaying)
		{
			//Update entities
			UpdateShip(mousePos);
			UpdateBullets();
			UpdateAsteroids(screenSize);

			//Player controls
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				PlaySound(shoot);
			}

			if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
			{
				PlaySound(engines);
			}

			//ScreenChecks
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
			
			CheckCollisions();

			//Game over

			if (gameOver)
			{
				isPlaying = false;
			}

		}
		//Pause
		else if (!gameOver)
		{
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
			{
				if (CollisionPointRec(mousePos, resumeButton.position, resumeButton.size))
					isPlaying = true;
				
				if (CollisionPointRec(mousePos, menuButton.position, menuButton.size))
					currentScreen = Menu;
			}
		}
		//Game Over
		else
		{
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
			{
				if (CollisionPointRec(mousePos, menuButton.position, menuButton.size))
					currentScreen = Menu;
			}
		}
	}

	void DrawGame(Vector2 screenSize)
	{
		ClearBackground(BLACK);
		DrawText(TextFormat("Lifes: %i", P1.lifes), 0, 0, 40, WHITE);
		DrawText(TextFormat("Score: %i", score), 0, static_cast<int>(screenSize.y) - 40, 40, WHITE);
		DrawShip();
		DrawBullets();
		DrawAsteroids();

		if (isPlaying)
		{
			DrawText("P", static_cast<int>(pauseButton.position.x), static_cast<int>(pauseButton.position.y), 40, WHITE);
		}

		if (!isPlaying && !gameOver)
		{
			DrawRectangle(0, 0, static_cast<int>(screenSize.x), static_cast<int>(screenSize.y), Fade(BLACK, 0.5f));

			Rectangle source = { 0, 0, (float)paused.width, (float)paused.height };
			Rectangle dest = { 0, 0, screenSize.x, screenSize.y };
			DrawTexturePro(paused, source, dest, { 0, 0 }, 0.0f, WHITE);

			Rectangle sourceResume = { 0, 0, (float)resumeTexture.width, (float)resumeTexture.height };
			Rectangle destResume = { resumeButton.position.x, resumeButton.position.y, resumeButton.size.x, resumeButton.size.y };
			DrawTexturePro(resumeTexture, sourceResume, destResume, { 0, 0 }, 0.0f, WHITE);

			Rectangle sourceMenu = { 0, 0, (float)menuButtonTexture.width, (float)menuButtonTexture.height };
			Rectangle destMenu = { menuButton.position.x, menuButton.position.y, menuButton.size.x, menuButton.size.y };
			DrawTexturePro(menuButtonTexture, sourceMenu, destMenu, { 0, 0 }, 0.0f, WHITE);
		}
		else if (gameOver)
		{
			DrawRectangle(0, 0, static_cast<int>(screenSize.x), static_cast<int>(screenSize.y), Fade(BLACK, 0.5f));

			Rectangle sourceDeath = { 0, 0, (float)deathScreen.width, (float)deathScreen.height };
			Rectangle destDeath = { 0, 0, screenSize.x, screenSize.y };
			DrawTexturePro(deathScreen, sourceDeath, destDeath, { 0, 0 }, 0.0f, WHITE);

			Rectangle sourceMenu = { 0, 0, (float)menuButtonTexture.width, (float)menuButtonTexture.height };
			Rectangle destMenu = { menuButton.position.x, menuButton.position.y, menuButton.size.x, menuButton.size.y };
			DrawTexturePro(menuButtonTexture, sourceMenu, destMenu, { 0, 0 }, 0.0f, WHITE);

			int scoreLength = MeasureText("Final Score: %i", 40);
			DrawText(TextFormat("Final Score: %i", score), static_cast<int>(screenSize.x / 2 - scoreLength / 2), static_cast<int>(menuButton.position.y) + 60, 40, WHITE);
		}
	}

	void CheckCollisions()
	{
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
