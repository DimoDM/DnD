#pragma once
#include"ECS/ECS.h"
#include"Structures/Collection.h"
#include"ECS/TransformComponent.h"
#include"Structures/Vector2D.h"
#include"ECS/StatsComponent.h"
#include"ECS/SaveLoadComponent.h"

class NextLevelSystem
{
	int x;
	int y;
	int mapLvl;
	Collection<Entity>* players = nullptr;

public:

	NextLevelSystem(int x, int y, int mapLvl, Collection<Entity>& players) {
		this->x = x;
		this->y = y;
		this->mapLvl = mapLvl;
		this->players = &players;
	}

	const bool isAtTheExit() const {
		for (int i = 0; i < players->getSize(); i++) {
			if (players->getElementByIndex(i)->getComponent<TransformComponent>().getPos() == Vector2D(x, y)) {
				if(players->getElementByIndex(i)->getComponent<StatsComponent>().getCompletedLevel() == mapLvl)
				players->getElementByIndex(i)->getComponent<StatsComponent>().completeLevel();
				players->getElementByIndex(i)->getComponent<TransformComponent>().setPos(1, 0);
				players->getElementByIndex(i)->getComponent<SaveLoadComponent>().save();
				return true;
			}
		}
		return false;
	}
};