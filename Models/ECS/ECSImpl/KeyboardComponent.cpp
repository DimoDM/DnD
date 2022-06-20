#include"../KeyboardComponent.h"

KeyboardComponent::KeyboardComponent() : Component() {
	type = 4;
}

void KeyboardComponent::init() {
	if (!entity->hasComponent<TransformComponent>()) entity->addComponent<TransformComponent>();
	transform = &entity->getComponent<TransformComponent>();
}

/// <summary>
/// ... read keyboard input and move player
/// </summary>
void KeyboardComponent::update() {
	char input;
	input = _getch();
	switch (input) {
	case 'a':
	case 'A': transform->setVel(-1, 0); break;
	case 'd':
	case 'D': transform->setVel(1, 0); break;
	case 's':
	case 'S': transform->setVel(0, 1); break;
	case 'w':
	case 'W': transform->setVel(0, -1); break;
	}
}