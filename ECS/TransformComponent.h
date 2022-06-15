#pragma once
#include"ECS.h"

class TransformComponent : public Component
{
	int x = 1;
	int y = 0;

public:

	TransformComponent() : Component() {
		type = 2;
	}
	TransformComponent(int x, int y) : Component() {
		type = 2;
		this->x = x;
		this->y = y;
	}

	void init() override {
	}

	void update() override {
	}
	void draw() override {
	}

	const int getX() const {
		return x;
	}
	const int getY() const {
		return y;
	}
};