#pragma once
#include "interactions.h"
#include <cmath>
#include <ctime>
#include "raymath.h"

int const maxAsteroids = 20;
int const screenAsteroids = 5;
float const timeBetweenSpawns = 2.0f;
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
    void SplitAsteroid(Asteroid& asteroid);
    void UpdateAsteroids(Vector2 screenSize);
    void DrawAsteroids();
    void SpawnAsteroid(int index, Vector2 screenSize);
    void LoadAsteroidsTexture();
    void UnloadAsteroidsTexture();
    int FindFreeAsteroid();
    int FindActiveAsteroids();