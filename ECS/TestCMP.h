#pragma once
#include"ECS.h"
#include<iostream>
class TestCMP : public Component
{
public:
	int test = 0;
	TestCMP() = default;
	TestCMP(int n) {
		test = n;
	}

	void init() override {
		type = 1;
	}

	void update() override {
		test--;
	}
	void draw() override {
		std::cout << test << std::endl;
	}
};