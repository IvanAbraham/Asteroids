#include "raylib.h"

bool CollisionRecRec(Vector2 pos1, Vector2 size1, Vector2 pos2, Vector2 size2)
{
    return (pos1.x < pos2.x + size2.x &&
        pos1.x + size1.x > pos2.x &&
        pos1.y < pos2.y + size2.y &&
        pos1.y + size1.y > pos2.y);
}

bool CollisionPointRec(Vector2 point, Vector2 rectPos, Vector2 rectSize)
{
    return (point.x >= rectPos.x &&
        point.x <= rectPos.x + rectSize.x &&
        point.y >= rectPos.y &&
        point.y <= rectPos.y + rectSize.y);
}