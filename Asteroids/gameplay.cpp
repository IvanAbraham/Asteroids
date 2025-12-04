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
                
                }
            }
        }
	}

	void DrawGame(Vector2 screenSize)
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

