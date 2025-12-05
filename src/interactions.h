#pragma once
#include "raylib.h"

bool CollisionRecRec(Vector2 pos1, Vector2 size1, Vector2 pos2, Vector2 size2);

bool CollisionPointRec(Vector2 point, Vector2 rectPos, Vector2 rectSize);

bool InScreenCheck(Vector2 position, float radius, Vector2 screenSize);

bool CollisionCircleCircle(Vector2 pos1, float radius1, Vector2 pos2, float radius2);