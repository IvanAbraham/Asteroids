#pragma once
#include "interactions.h"
#include <cmath>

const int maxAsteroids = 1;

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
void UpdateAsteroids();
void DrawAsteroids();