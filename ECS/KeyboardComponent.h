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
		type = 3;
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
		case 'A': cout << input; break;
		case 'd':
		case 'D': cout << input; break;
		case 's':
		case 'S': cout << input; break;
		case 'w':
		case 'W': cout << input; break;
		}
	}
	void draw() override {
	}
};