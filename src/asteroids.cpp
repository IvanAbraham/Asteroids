#include "asteroids.h"

Asteroid asteroids[maxAsteroids];
Texture2D asteroidsTexture;
float spawnTimer = 0.0f;

    void InitAsteroids(Vector2 screenSize)
    {
        static bool seedInitialized = false;
        int const startingAsteroids = 2;

        if (!seedInitialized)
        {
            srand(static_cast<int>(time(NULL)));
            seedInitialized = true;
        }

        for (int i = 0; i < maxAsteroids; i++)
        {
            asteroids[i].isActive = false;
        }

        spawnTimer = 0;

        for (int i = 0; i < startingAsteroids; i++)
        {
            SpawnAsteroid(i, screenSize);
        }
    }

    void SetAsteroidSize(Asteroid& asteroid, Size size)
    {
        switch (size)
        {
        case small: 
            asteroid.radius = 20.0f + (rand() % 10);
            asteroid.speed = 200.0f + (rand() % 100);
            break;

        case medium: 
            asteroid.radius = 35.0f + (rand() % 15);
            asteroid.speed = 150.0f + (rand() % 80);
            break;

        case big: asteroid.radius = 60.0f + (rand() % 20);
            asteroid.speed = 100.0f + (rand() % 60);
            break;
        }
        asteroid.size = size;
    }
    
    void LoadAsteroidsTexture()
    {
        asteroidsTexture = LoadTexture("../res/sprites/Game/Asteroid.png");
    }

    void UnloadAsteroidsTexture()
    {
        UnloadTexture(asteroidsTexture);
    }

    void SpawnAsteroid(int index, Vector2 screenSize)
    {
        asteroids[index].isActive = true;

        Size sizeType = static_cast<Size>(rand() % 3);
        
        SetAsteroidSize(asteroids[index], sizeType);

        int edge = rand() % 4;
        float margin = asteroids[index].radius + 50;

        switch (edge)
        {
        case 0: //From top
            asteroids[index].position.x = static_cast<float>(rand() % static_cast<int>(screenSize.x));
            asteroids[index].position.y = -margin;
            break;
        case 1: //From right
            asteroids[index].position.x = screenSize.x + margin;
            asteroids[index].position.y = static_cast<float>(rand() % static_cast<int>(screenSize.y));
            break;
        case 2: //From bottom
            asteroids[index].position.x = static_cast<float>(rand() % static_cast<int>(screenSize.x));
            asteroids[index].position.y = screenSize.y + margin;
            break;
        case 3: //From left
            asteroids[index].position.x = -margin;
            asteroids[index].position.y = static_cast<float>(rand() % static_cast<int>(screenSize.y));
            break;
        }

        asteroids[index].targetPosition.x = 100.0f + (rand() % ((int)screenSize.x - 200));
        asteroids[index].targetPosition.y = 100.0f + (rand() % ((int)screenSize.y - 200));

        float dx = asteroids[index].targetPosition.x - asteroids[index].position.x;
        float dy = asteroids[index].targetPosition.y - asteroids[index].position.y;
        float angle = atan2f(dy, dx);

        asteroids[index].velocity.x = cosf(angle) * asteroids[index].speed;
        asteroids[index].velocity.y = sinf(angle) * asteroids[index].speed;
    }

    void SpawnFragment(int index, Size size, Vector2 position, Vector2 direction)
    {
        asteroids[index].isActive = true;

        SetAsteroidSize(asteroids[index], size);

        asteroids[index].position = position;

        Vector2 normalizedDir = Vector2Normalize(direction);
        asteroids[index].velocity = Vector2Scale(normalizedDir, asteroids[index].speed);
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

        spawnTimer += GetFrameTime();

        if (spawnTimer > timeBetweenSpawns)
        {
            int index = FindFreeAsteroid();

            if (index != -1 && FindActiveAsteroids() < screenAsteroids)
                SpawnAsteroid(index, screenSize);

            spawnTimer = 0;
        }
    }

    void DrawAsteroids()
    {
        for (int i = 0; i < maxAsteroids; i++)
        {
            if (asteroids[i].isActive)
            {
                Rectangle source = { 0, 0, (float)asteroidsTexture.width, (float)asteroidsTexture.height };
                Rectangle dest = { asteroids[i].position.x, asteroids[i].position.y, asteroids[i].radius * 2.0f, asteroids[i].radius * 2.0f };
                Vector2 origin = { asteroids[i].radius, asteroids[i].radius };

                DrawTexturePro(asteroidsTexture, source, dest, origin, 0.0f, WHITE);
            }
        }
    }

    int FindFreeAsteroid()
    {
        for (int i = 0; i < maxAsteroids; i++)
        {
            if (!asteroids[i].isActive)
                return i;
        }

        return -1;
    }
    
    int FindActiveAsteroids()
    {
        int activeAsteroids = 0;

        for (int i = 0; i < maxAsteroids; i++)
        {
            if (asteroids[i].isActive)
                activeAsteroids++;
        }

        return activeAsteroids;
    }

    void SplitAsteroid(Asteroid& asteroid)
    {
        int const fragAmount = 2;
        float const fragmentAngle = 30.0f;
        float angle = fragmentAngle;

        Asteroid parent = asteroid;
        asteroid.isActive = false;

        if (parent.size == big)
            parent.size = medium;
        else if (parent.size == medium)
            parent.size = small;
        else
            return;
        
        for (int i = 0; i < fragAmount; i++)
        {
            int index = FindFreeAsteroid();

            if (index != -1)
            {
                if (i % 2 != 0)
                    angle = -fragmentAngle;
                
                SpawnFragment(index, parent.size, parent.position, Vector2Rotate(parent.velocity, angle * DEG2RAD));
            }
        }
    }
      