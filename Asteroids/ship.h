#pragma once
#include "raylib.h"
#include "raymath.h"
#include "interactions.h"
#include <cmath>

int const maxBullets = 30;

struct Ship
{
	Vector2 spriteSize;
	Vector2 position;
	Vector2 targetPosition;
	float radius;
	float speed;
	float rotation;
};

struct Bullet
{
	Vector2  position;
	Vector2 velocity;
	float radius;
	float speed;
	bool isActive;
};

extern Ship P1;
extern Bullet bullets[maxBullets];

void InitShip(Vector2 screenSize);
void UpdateShip(Vector2 mousePos);
void MoveShip(Vector2 targetPos, Vector2& currentPos, float speed);

void ShootBullet(Vector2 shipPos, float shipRotation);
void UpdateBullets();
void DrawBullets();

void DrawShip(Ship player);