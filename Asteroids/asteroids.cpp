#include "asteroids.h"
#include <ctime>

    Asteroid asteroids[maxAsteroids];

    void InitAsteroids(Vector2 screenSize)
    {

        static bool seedInitialized = false;
        if (!seedInitialized)
        {
            srand(time(NULL));
            seedInitialized = true;
        }

        for (int i = 0; i < maxAsteroids; i++)
        {
            SpawnAsteroid(i, screenSize);
        }
    }

    void SpawnAsteroid(int iteration, Vector2 screenSize)
    {
        asteroids[iteration].isActive = true;

        int sizeType = rand() % 3;
        switch (sizeType) // Three sizes
        {
        case 0: //Small size
            asteroids[iteration].radius = 20 + (rand() % 10);
            asteroids[iteration].speed = 200 + (rand() % 100);
            break;
        case 1: //Medium size
            asteroids[iteration].radius = 35 + (rand() % 15);
            asteroids[iteration].speed = 150 + (rand() % 80);
            break;
        case 2: //Big size
            asteroids[iteration].radius = 60 + (rand() % 20);
            asteroids[iteration].speed = 100 + (rand() % 60);
            break;
        }

        int edge = rand() % 4;
        float margin = asteroids[iteration].radius + 50;

        switch (edge)
        {
        case 0: //From top
            asteroids[iteration].position.x = rand() % (int)screenSize.x;
            asteroids[iteration].position.y = -margin;
            break;
        case 1: //From right
            asteroids[iteration].position.x = screenSize.x + margin;
            asteroids[iteration].position.y = rand() % (int)screenSize.y;
            break;
        case 2: //From bottom
            asteroids[iteration].position.x = rand() % (int)screenSize.x;
            asteroids[iteration].position.y = screenSize.y + margin;
            break;
        case 3: //From left
            asteroids[iteration].position.x = -margin;
            asteroids[iteration].position.y = rand() % (int)screenSize.y;
            break;
        }

        asteroids[iteration].targetPosition.x = 100 + (rand() % ((int)screenSize.x - 200));
        asteroids[iteration].targetPosition.y = 100 + (rand() % ((int)screenSize.y - 200));

        float dx = asteroids[iteration].targetPosition.x - asteroids[iteration].position.x;
        float dy = asteroids[iteration].targetPosition.y - asteroids[iteration].position.y;
        float angle = atan2f(dy, dx);

        asteroids[iteration].velocity.x = cosf(angle) * asteroids[iteration].speed;
        asteroids[iteration].velocity.y = sinf(angle) * asteroids[iteration].speed;
    }

    void UpdateAsteroids(Vector2 screenSize)
    {
        for (int i = 0; i < maxAsteroids; i++)
        {
            if (asteroids[i].isActive)
            {
                asteroids[i].position.x += asteroids[i].velocity.x * GetFrameTime();
                asteroids[i].position.y += asteroids[i].velocity.y * GetFrameTime();

                float margin = asteroids[i].radius;
                if (asteroids[i].position.x < -margin ||
                    asteroids[i].position.x > screenSize.x + margin ||
                    asteroids[i].position.y < -margin ||
                    asteroids[i].position.y > screenSize.y + margin)
                {
                    if (asteroids[i].position.x < 0 - margin)
                    {
                        asteroids[i].position.x = screenSize.x + margin;
                    }
                    else if (asteroids[i].position.x > screenSize.x + margin)
                    {
                        asteroids[i].position.x = 0 - margin;
                    }
                    if (asteroids[i].position.y > screenSize.y + margin)
                    {
                        asteroids[i].position.y = 0 - margin;
                    }
                    else if (asteroids[i].position.y < 0 - margin)
                    {
                        asteroids[i].position.y = screenSize.y + margin;
                    }
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
                DrawCircleLines(asteroids[i].position.x, asteroids[i].position.y,
                    asteroids[i].radius, WHITE);

            }
        }
    }
