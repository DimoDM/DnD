#pragma once
#include"ECS.h"
#include"../Structures/Collection.h"
#include"../Game.h"
#include"Components.h"
#include<iostream>
using namespace std;

class MonsterAIComponent : public Component
{
	bool isVisible = true;
	Collection<Entity>* players = nullptr;

public:

	MonsterAIComponent() : Component() {
		type = 7;
	}

	MonsterAIComponent(Collection<Entity>& ps) : Component() {
		type = 7;
		players = &ps;
	}


	void init() override {
	}

	void update() override {

	}
	void draw() override {
		cout<<players->getElementByIndex(0)->getComponent<TransformComponent>().getX()<<endl;
	}

};