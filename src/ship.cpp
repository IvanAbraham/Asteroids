#include "ship.h"

Ship P1;
Bullet bullets[maxBullets];

Texture2D playerTexture;

void InitShip(Vector2 screenSize)
{
	P1.isHurt = false;
	P1.lifes = 3;
	P1.speed = 500;
	P1.position = { screenSize.x / 2, screenSize.y / 2 };
	P1.radius = screenSize.y / 30;
	P1.spriteSize.x = (P1.radius * 2) + 10;
	P1.spriteSize.y = (P1.radius * 2) + 10;
	P1.rotation = 0.0f;
	P1.velocity = { 0.0f, 0.0f };
	P1.targetPosition = P1.position;

	for (int i = 0; i < maxBullets; i++)
	{
		bullets[i].isActive = false;
	}
}

void LoadShipTexture()
{
	playerTexture = LoadTexture("../res/sprites/Game/Ship.png");
}

void UpdateShip(Vector2 mousePos)
{
	float const acceleration = 2000.0f;

	Vector2 dif = { mousePos.x - P1.position.x, mousePos.y - P1.position.y };
	P1.rotation = atan2f(dif.y, dif.x) * RAD2DEG;

	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		float rotationAngle = P1.rotation * DEG2RAD;
		Vector2 direction = { cosf(rotationAngle), sinf(rotationAngle) };

		P1.velocity.x += direction.x * acceleration * GetFrameTime();
		P1.velocity.y += direction.y * acceleration * GetFrameTime();
	}

	P1.position.x += P1.velocity.x * GetFrameTime();
	P1.position.y += P1.velocity.y * GetFrameTime();

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		ShootBullet(P1.position, P1.rotation);
	}
} 


void ShootBullet(Vector2 shipPos, float shipRotation)
{
	for (int i = 0; i < maxBullets; i++)
	{
		if (!bullets[i].isActive)
		{
			bullets[i].isActive = true;
			bullets[i].position = shipPos;
			bullets[i].radius = P1.radius * 0.25f;
			bullets[i].speed = 1000.0f;

			float bulletAngle = shipRotation * DEG2RAD;
			bullets[i].velocity.x = cosf(bulletAngle) * bullets[i].speed;
			bullets[i].velocity.y = sinf(bulletAngle) * bullets[i].speed;

			break;
		}
	}
}

void UpdateBullets()
{
	for (int i = 0; i < maxBullets; i++)
	{
		if (bullets[i].isActive)
		{
			bullets[i].position.x += bullets[i].velocity.x * GetFrameTime();
			bullets[i].position.y += bullets[i].velocity.y * GetFrameTime();
		}

		if (bullets[i].position.x < 0 - bullets[i].radius || bullets[i].position.x > 1280 ||
			bullets[i].position.y < 0 - bullets[i].radius || bullets[i].position.y > 900)
		{
			bullets[i].isActive = false;
		}
	}
}

void DrawShip()
{

	Vector2 origin = { P1.spriteSize.x / 2.0f, P1.spriteSize.y / 2.0f };
	Rectangle source = { 0, 0, (float)playerTexture.width, (float)playerTexture.height };
	Rectangle dest = { P1.position.x, P1.position.y, P1.spriteSize.x, P1.spriteSize.y };

	if (P1.isHurt)
	{
		DrawTexturePro(playerTexture, source, dest, origin, P1.rotation + 90.0f, RED);
	}
	else
	{
		DrawTexturePro(playerTexture, source, dest, origin, P1.rotation + 90.0f, WHITE);
	}
}

void DrawBullets()
{

	for (int i = 0; i < maxBullets; i++)
	{
		if (bullets[i].isActive)
		{
			DrawCircleV(bullets[i].position, bullets[i].radius, WHITE);
		}
	}

}