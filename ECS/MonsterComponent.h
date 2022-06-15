#pragma once
#include"Entity.h"
class MonsterComponent : public Component
{

public:
	int test = 0;
	MonsterComponent() : Component() {
		type = 2;
	}
	MonsterComponent(int n) : Component() {
		test = n;
		type = 2;
	}
	Component* clone() const override {
		return new MonsterComponent(*this);

	}
	void init() override {
		type = 1;
	}

	void update() override {

	}
	void draw() override {
		std::cout << "I'm monster: " << test << std::endl;
	}
};