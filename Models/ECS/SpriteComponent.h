#pragma once
#include"ECS.h"
#include"../TextureManager.h"

class SpriteComponent : public Component
{
	TransformComponent* transform;
	char texture = '@';

public:

	SpriteComponent() : Component() {
		type = 3;
	}
	SpriteComponent(char tex) : Component() {
		type = 3;
		texture = tex;
	}

	void init() override {
		if (!entity->hasComponent<TransformComponent>()) entity->addComponent<TransformComponent>();
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override {
	}
	void draw() override {
		TextureManager::LoadTexture(texture, transform->getX(), transform->getY());
	}
};