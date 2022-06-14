#pragma once
#include"ECS.h"
#include<iostream>
class TestComponent : public Component
{
public:
	int test = 0;

	void init() override {
		type = 0;
	}

	void update() override {
		test++;
	}
	void draw() override {
		std::cout << test << std::endl;
	}
};