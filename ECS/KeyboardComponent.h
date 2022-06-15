#pragma once
#include"ECS.h"
#include<conio.h>
#include<iostream>
using namespace std;

class KeyboardComponent : public Component
{
	TransformComponent * transform;

public:

	KeyboardComponent() : Component() {
		type = 4;
	}


	void init() override {
		if (!entity->hasComponent<TransformComponent>()) entity->addComponent<TransformComponent>();
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override {
		char input;
		input = _getch();
		switch (input) {
		case 'a':
		case 'A': transform->setVel(-1, 0); break;
		case 'd':
		case 'D': transform->setVel(1, 0); break;
		case 's':
		case 'S': transform->setVel(0, 1); break;
		case 'w':
		case 'W': transform->setVel(0, -1); break;
		}
	}
	void draw() override {
	}
};