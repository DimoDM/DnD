#pragma once
#include"Structures/Vector2D.h"

class GetDistance
{
public:
	static int getDistance(const Vector2D& monsterPos, const Vector2D& playerPos) {
		Vector2D distance2D = { playerPos.x - monsterPos.x, playerPos.y - monsterPos.y };
		return (abs(distance2D.x) + abs(distance2D.y));
	}

};