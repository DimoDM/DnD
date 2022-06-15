#pragma once
#include"ECS.h"

class ColliderComponent : public Component
{
	int x = 0;
	int y = 0;

public:

	ColliderComponent() : Component() {
		type = 1;
	}

	ColliderComponent(int x, int y) : Component() {
		type = 1;
		this->x = x;
		this->y = y;
	}

	void init() override {
	}

	void update() override {
	}
	void draw() override {
	}
};