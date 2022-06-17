#pragma once
#include"ECS.h"
#include"../Structures/Collection.h"
#include"../Game.h"
#include"Components.h"
#include<iostream>
#include"../Structures/Vector2D.h"
#include<math.h>
using namespace std;

class MonsterAIComponent : public Component
{
	bool isVisible = true;
	Collection<Entity>* players;
	TransformComponent* transform;

	const int getIndexOfTheClosestPlayer() const {
		Vector2D playerPos;
		const Vector2D MonsterPos = transform->getPos();
		Vector2D distance2D;
		int distance = ConsoleViewer::getInstance()->getMaxWidth() * 3;
		int index;
		for (int i = 0; i < players->getSize(); i++) {
			playerPos = players->getElementByIndex(0)->getComponent<TransformComponent>().getPos();
			distance2D = (playerPos.Subtract(MonsterPos));
			int curDis = abs(distance2D.x) + abs(distance2D.y);
			if (distance > curDis) {
				distance = curDis;
				index = i;
			}
		}
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
		if (entity->hasComponent<TransformComponent>())
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override {


	}
	void draw() override {
		cout<<players->getElementByIndex(0)->getComponent<TransformComponent>().getX()<<endl;
	}

};