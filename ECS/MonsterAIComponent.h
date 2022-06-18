#pragma once
#include"ECS.h"
#include"../Structures/Collection.h"
#include"../Game.h"
#include"Components.h"
#include<iostream>
#include"../Structures/Vector2D.h"
#include<math.h>
#include"../generateFreeVector2D.h"
using namespace std;

class MonsterAIComponent : public Component
{
	bool isVisible = true;
	Collection<Entity>* players;
	TransformComponent* transform;
	const int MAXDISTANCE = ConsoleViewer::getInstance()->getMaxWidth() * 3;

	const int getDistanceToPlayer(const Vector2D& monsterPos, const Vector2D& playerPos) const {
		Vector2D distance2D = { playerPos.x - monsterPos.x, playerPos.y - monsterPos.y };
		return (abs(distance2D.x) + abs(distance2D.y));
	}

	const int getIndexOfTheClosestPlayer() const {

		const Vector2D MonsterPos = transform->getPos();
		int distance = MAXDISTANCE;
		int index;
		for (int i = 0; i < players->getSize(); i++) {
			int curDis = getDistanceToPlayer(MonsterPos, players->getElementByIndex(i)->getComponent<TransformComponent>().getPos());
			if (distance > curDis) {
				distance = curDis;
				index = i;
			}
		}
		return index;
	}


	const Vector2D newVel(const Vector2D& monsterPos, const Vector2D& playerPos) const {
		int distance = MAXDISTANCE;
		int disToPlayer[4] = { distance };
		Vector2D vel[4];
		int index = 0;
		vel[0] = { monsterPos.x + 1, monsterPos.y };
		vel[1] = { monsterPos.x - 1, monsterPos.y };
		vel[2] = { monsterPos.x, monsterPos.y + 1 };
		vel[3] = { monsterPos.x, monsterPos.y - 1 };

		for (int i = 0; i < 4; i++) {
			disToPlayer[i] = getDistanceToPlayer(vel[i], playerPos);
			if (distance > disToPlayer[i]) {
				distance = disToPlayer[i];
				index = i;
			}
		}

		return vel[index].Subtract(monsterPos);

	}


public:
	
	MonsterAIComponent() : Component() {
		type = 7;
	}

	MonsterAIComponent(Collection<Entity>& ps) : Component() {
		type = 7;
		players = &ps;
	}


	void init() override {
		if (!entity->hasComponent<TransformComponent>()) {
			Vector2D pos = Random::generateValidCoordinates();
			entity->addComponent<TransformComponent>(pos.x, pos.y);
		}
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override {
		const Vector2D MonsterPos = transform->getPos();
		const Vector2D PlayerPos = players->getElementByIndex(getIndexOfTheClosestPlayer())->getComponent<TransformComponent>().getPos();
		const Vector2D newVelocity = newVel(MonsterPos, PlayerPos);
		transform->setVel(newVelocity.x, newVelocity.y);

	}
	void draw() override {
		//cout<<players->getElementByIndex(0)->getComponent<TransformComponent>().getX()<<endl;
	}

};