#pragma once
#include"ECS.h"
#include<iostream>
class TestComponent : public Component
{
public:

	TestComponent() : Component() {
		type = 0;
	}

	int test = 0;

	Component* clone() const override {
		return new TestComponent(*this);

	}

	void init() override {
		type = 0;
	}

	void update() override {
		test++;
	}
	void draw() override {
		std::cout << "I'm a player: " << test << std::endl;
	}
};