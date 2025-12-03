
#include "asteroids.h"

Asteroid asteroids[maxAsteroids];

void InitAsteroids(Vector2 screenSize)
{
	
	for (int i = 0; i < maxAsteroids; i++)
	{
		asteroids[i].speed = 200;
		asteroids[i].radius = 100;


		asteroids[i].position.x = screenSize.x - 100;
		asteroids[i].position.y = screenSize.y / 2;


		asteroids[i].velocity.x = -200;
		asteroids[i].velocity.y = 0;

		asteroids[i].isActive = true;
	}
}

void UpdateAsteroids()
{
	for (int i = 0; i < maxAsteroids; i++)
	{
		if (asteroids[i].isActive)
		{
			asteroids[i].position.x += asteroids[i].velocity.x * GetFrameTime();
			asteroids[i].position.y += asteroids[i].velocity.y * GetFrameTime();

			if (asteroids[i].position.x < -100 || asteroids[i].position.x > 1380 ||
				asteroids[i].position.y < -100 || asteroids[i].position.y > 820)
			{
				asteroids[i].isActive = false;
			}
		}
	}
}


void DrawAsteroids()
{
	for (int i = 0; i < maxAsteroids; i++)
	{
		if (asteroids[i].isActive)
		{
			DrawCircleLines(asteroids[i].position.x, asteroids[i].position.y, asteroids[i].radius, WHITE);
		}
	}
}


