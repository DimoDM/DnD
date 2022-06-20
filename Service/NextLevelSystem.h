#pragma once
#include"../Models/ECS/ECS.h"
#include"../Structures/Collection.h"

class NextLevelSystem
{
	int x;
	int y;
	int mapLvl;
	Collection<Entity>* players = nullptr;

public:

	NextLevelSystem(int x, int y, int mapLvl, Collection<Entity>& players);

	/// <summary>
	/// return true if player is on exit of map and prepare him to move on next map
	/// </summary>
	/// <returns></returns>
	const bool isAtTheExit() const;
};