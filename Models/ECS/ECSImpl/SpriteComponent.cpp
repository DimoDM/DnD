#include"../SpriteComponent.h"
#include"../TransformComponent.h"
#include"../../../Service/TextureManager.h"


SpriteComponent::SpriteComponent() : Component() {
		type = 3;
}
SpriteComponent::SpriteComponent(char tex) : Component() {
		type = 3;
		texture = tex;
}

/// <summary>
/// initialize component
/// </summary>
void SpriteComponent::init() {
	if (!entity->hasComponent<TransformComponent>()) entity->addComponent<TransformComponent>();
	transform = &entity->getComponent<TransformComponent>();
}

/// <summary>
/// Draw logic of entity
/// </summary>
void SpriteComponent::draw() {
	TextureManager::LoadTexture(texture, transform->getX(), transform->getY());
}