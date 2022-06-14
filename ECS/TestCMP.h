#pragma once
#include"Entity.h"
#include<iostream>
class TestCMP : public Component
{

	TestComponent *t;
public:
	int test = 0;
	TestCMP() : Component() {
		type = 1;
	}
	TestCMP(int n) : Component() {
		test = n;
		type = 1;
	}
	Component* clone() const override {
		return new TestCMP(*this);

	}
	void init() override {
		type = 1;
		t = &entity->getComponent<TestComponent>();
	}

	void update() override {
		std::cout << "asd" << t->test << std::endl;
		test--;
	}
	void draw() override {
		std::cout << "CMP: " << test << std::endl;
	}
};