#pragma once
#include "interactions.h"
#include <cmath>
#include <ctime>
#include "raymath.h"

const int maxAsteroids = 20;
enum Size { small = 0, medium, big };

struct Asteroid
{
    bool isActive;
    float radius;
    float speed;
    Size size;
    Vector2 position;
    Vector2 velocity;
    Vector2 dir;
    Vector2 targetPosition;        
};

    extern Asteroid asteroids[maxAsteroids];

    void InitAsteroids(Vector2 screenSize);
    void SetAsteroidSize(Asteroid& asteroid, Size size);
    void SpawnFragment(int index, Size size, Vector2 position, Vector2 direction);
    void UpdateAsteroids(Vector2 screenSize);
    void DrawAsteroids();
    void SpawnAsteroid(int index, Vector2 screenSize);
    void LoadAsteroidsTexture();
