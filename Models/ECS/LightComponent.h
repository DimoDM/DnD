#pragma once
#include"ECS.h"
#include"TransformComponent.h"
//last component to complete
class LightComponent : public Component
{
	TransformComponent* transform;
	Manager* manager = nullptr;

public:

	LightComponent() : Component() {
		type = 5;
	}

	LightComponent(Manager& m) : Component() {
		type = 5;
		manager = &m;
	}

	void init() override {
		if (!entity->hasComponent<TransformComponent>()) entity->addComponent<TransformComponent>();
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override {

	}
	void draw() override {
	}
};