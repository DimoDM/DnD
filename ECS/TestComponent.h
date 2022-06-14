#pragma once
#include"Entity.h"
#include<iostream>
class TestComponent : public Component
{
public:

	TestComponent() : Component() {}

	int test = 0;

	void init() override {
		type = 0;
	}

	void update() override {
		test++;
	}
	void draw() override {
		std::cout << "Test" << test << std::endl;
	}
};