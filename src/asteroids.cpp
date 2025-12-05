#include "asteroids.h"


    Asteroid asteroids[maxAsteroids];

    void InitAsteroids(Vector2 screenSize)
    {

        static bool seedInitialized = false;
        if (!seedInitialized)
        {
            srand(static_cast<int>(time(NULL)));
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
            asteroids[iteration].radius = 20.0f + (rand() % 10);
            asteroids[iteration].speed = 200.0f + (rand() % 100);
            break;
        case 1: //Medium size
            asteroids[iteration].radius = 35.0f + (rand() % 15);
            asteroids[iteration].speed = 150.0f + (rand() % 80);
            break;
        case 2: //Big size
            asteroids[iteration].radius = 60.0f + (rand() % 20);
            asteroids[iteration].speed = 100.0f + (rand() % 60);
            break;
        }

        int edge = rand() % 4;
        float margin = asteroids[iteration].radius + 50;

        switch (edge)
        {
        case 0: //From top
            asteroids[iteration].position.x = static_cast<float>(rand() % static_cast<int>(screenSize.x));
            asteroids[iteration].position.y = -margin;
            break;
        case 1: //From right
            asteroids[iteration].position.x = screenSize.x + margin;
            asteroids[iteration].position.y = static_cast<float>(rand() % static_cast<int>(screenSize.y));
            break;
        case 2: //From bottom
            asteroids[iteration].position.x = static_cast<float>(rand() % static_cast<int>(screenSize.x));
            asteroids[iteration].position.y = screenSize.y + margin;
            break;
        case 3: //From left
            asteroids[iteration].position.x = -margin;
            asteroids[iteration].position.y = static_cast<float>(rand() % static_cast<int>(screenSize.y));
            break;
        }

        asteroids[iteration].targetPosition.x = 100.0f + (rand() % ((int)screenSize.x - 200));
        asteroids[iteration].targetPosition.y = 100.0f + (rand() % ((int)screenSize.y - 200));

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

            else
            {
                static float respawnTimer[maxAsteroids] = { 0 };
                respawnTimer[i] += GetFrameTime();

                if (respawnTimer[i] > 1.0)
                {
                    SpawnAsteroid(i, screenSize);
                    respawnTimer[i] = 0;
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
                DrawCircleLines(static_cast<int>(asteroids[i].position.x), static_cast<int>(asteroids[i].position.y), asteroids[i].radius, WHITE);

            }
        }
    }
