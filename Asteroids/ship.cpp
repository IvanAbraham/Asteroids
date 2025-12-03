#include "ship.h"

Ship P1;
Bullet bullets[MAX_BULLETS];

void InitShip(Vector2 screenSize)
{
	P1.speed = 500;
	P1.position = { screenSize.x / 2, screenSize.y / 2 };
	P1.radius = screenSize.y / 25;
	P1.spriteSize.x = (P1.radius * 2) + 10;
	P1.spriteSize.y = (P1.radius * 2) + 10;
	P1.rotation = 0.0f;
	P1.targetPosition = P1.position;

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		bullets[i].isActive = false;
	}
}

void UpdateShip(Vector2 mousePos)
{
	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{

		P1.targetPosition = GetMousePosition();
		
	}
	
	Vector2 dif = {mousePos.x - P1.position.x, mousePos.y - P1.position.y};
	P1.rotation = atan2f(dif.y, dif.x) * RAD2DEG;

	MoveShip(P1.targetPosition, P1.position, P1.speed);

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		ShootBullet(P1.position, P1.rotation);
	}
} 

void MoveShip(Vector2 targetPos, Vector2 &currentPos, float speed)
{

	float dx = targetPos.x - currentPos.x;
	float dy = targetPos.y - currentPos.y;
	float distance = sqrtf(dx * dx + dy * dy);

	if (distance > 0)
	{
		float directionX = dx / distance;
		float directionY = dy / distance;

		currentPos.x += directionX * speed * GetFrameTime();
		currentPos.y += directionY * speed * GetFrameTime();
	}

}

void ShootBullet(Vector2 shipPos, float shipRotation)
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (!bullets[i].isActive)
		{
			bullets[i].isActive = true;
			bullets[i].position = shipPos;
			bullets[i].radius = P1.radius * 0.25;
			bullets[i].speed = 1000;

			float bulletAngle = shipRotation * DEG2RAD;
			bullets[i].velocity.x = cosf(bulletAngle) * bullets[i].speed;
			bullets[i].velocity.y = sinf(bulletAngle) * bullets[i].speed;

			break;
		}
	}
}

void UpdateBullets()
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (bullets[i].isActive)
		{
			bullets[i].position.x += bullets[i].velocity.x * GetFrameTime();
			bullets[i].position.y += bullets[i].velocity.y * GetFrameTime();
		}

		if (bullets[i].position.x < -50 || bullets[i].position.x > 1330 ||
			bullets[i].position.y < -50 || bullets[i].position.y > 770)
		{
			bullets[i].isActive = false;
		}
	}
}

void DrawShip(Ship player)
{
	
	DrawCircleLines(P1.position.x, P1.position.y, P1.radius, PINK);

	float rotationAngle = player.rotation * DEG2RAD;
	Vector2 endPoint = {
		player.position.x + cosf(rotationAngle) * player.radius,
		player.position.y + sinf(rotationAngle) * player.radius
	};
	DrawLineEx(player.position, endPoint, 2, SKYBLUE);

}

void DrawBullets()
{

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (bullets[i].isActive)
		{
			DrawCircleV(bullets[i].position, bullets->radius, WHITE);
		}
	}

}