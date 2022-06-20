#include"../GetDistance.h"

/// <summary>
	/// get distance between two coordinates
	/// </summary>
	/// <param name="monsterPos"></param>
	/// <param name="playerPos"></param>
	/// <returns></returns>
	int GetDistance::getDistance(const Vector2D& monsterPos, const Vector2D& playerPos) {
	Vector2D distance2D = { playerPos.x - monsterPos.x, playerPos.y - monsterPos.y };
	return (abs(distance2D.x) + abs(distance2D.y));
}