#pragma once
#include"ECS/ECS.h"
#include"GetDistance.h"
#include"ECS/TransformComponent.h"

class BattleSystem
{
	Collection<Entity>* players;
	Collection<Entity>* monsters;
public:

	BattleSystem(Collection<Entity>& ps, Collection<Entity>& ms) {
		players = &ps;
		monsters = &ms;
	}

	bool listenForBattle() {
		for (int i = 0; i < players->getSize(); i++) {
			for (int j = 0; j < monsters->getSize(); j++) {
				if (GetDistance::getDistance(players->getElementByIndex(i)->getComponent<TransformComponent>().getPos(),
					monsters->getElementByIndex(j)->getComponent<TransformComponent>().getPos()) <= 1) return true;
			}
		}
		return false;
	}

	void update() {}

	void draw() {}
};