#pragma once
#include"ECS.h"
#include"../Structures/String.h"

class PlayerComponent : public Component
{
	String name = "Player";

public:

	PlayerComponent() : Component(){
		type = 11;
	}

	PlayerComponent(const char* name) : Component() {
		type = 11;
		this->name = name;
	}

	void init() override {}

	const char* getName() const {
		return name.c_str();
	}


};