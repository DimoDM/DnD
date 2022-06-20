#include"../PlayerComponent.h"

PlayerComponent::PlayerComponent() : Component() {
	type = 11;
}

PlayerComponent::PlayerComponent(const char* name) : Component() {
	type = 11;
	this->name = name;
}


const char* PlayerComponent::getName() const {
	return name.c_str();
}
