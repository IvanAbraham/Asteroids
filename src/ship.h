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
	Vector2 velocity;
	float radius;
	float speed;
	float rotation;
	int lifes;
	bool isHurt;
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
void LoadShipTexture();
void ShootBullet(Vector2 shipPos, float shipRotation);
void UpdateBullets();
void DrawBullets();
void DrawShip();