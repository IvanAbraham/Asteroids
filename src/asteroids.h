#pragma once
#include "interactions.h"
#include <cmath>
#include <ctime>

    const int maxAsteroids = 5;

    struct Asteroid
    {
        bool isActive;
        float radius;
        float speed;
        Vector2 position;
        Vector2 velocity;
        Vector2 dir;
        Vector2 targetPosition;
    };

    extern Asteroid asteroids[maxAsteroids];

    void InitAsteroids(Vector2 screenSize);
    void UpdateAsteroids(Vector2 screenSize);
    void DrawAsteroids();
    void SpawnAsteroid(int index, Vector2 screenSize);
    void LoadAsteroidsTexture();