#pragma once
#include"../Structures/Vector2D.h"

class GetDistance
{
public:
	/// <summary>
	/// get distance between two coordinates
	/// </summary>
	/// <param name="monsterPos"></param>
	/// <param name="playerPos"></param>
	/// <returns></returns>
	static int getDistance(const Vector2D& monsterPos, const Vector2D& playerPos);

};