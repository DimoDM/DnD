#include"../NextLevelSystem.h"
#include"../../Models/ECS/TransformComponent.h"
#include"../../Structures/Vector2D.h"
#include"../../Models/ECS/StatsComponent.h"
#include"../../Models/ECS/SaveInFileComponent.h"
NextLevelSystem::NextLevelSystem(int x, int y, int mapLvl, Collection<Entity>& players) {
	this->x = x;
	this->y = y;
	this->mapLvl = mapLvl;
	this->players = &players;
}

const bool NextLevelSystem::isAtTheExit() const {
	for (int i = 0; i < players->getSize(); i++) {
		if (players->getElementByIndex(i)->getComponent<TransformComponent>().getPos() == Vector2D(x, y)) {
			if (players->getElementByIndex(i)->getComponent<StatsComponent>().getCompletedLevel() == mapLvl)
				players->getElementByIndex(i)->getComponent<StatsComponent>().completeLevel();
			players->getElementByIndex(i)->getComponent<TransformComponent>().setPos(1, 0);
			players->getElementByIndex(i)->getComponent<SaveInFileComponent>().save();
			return true;
		}
	}
	return false;
}