#pragma once
#include"ECS.h"
#include"TransformComponent.h"

/// <summary>
/// this component is responcible for drawing of entity
/// </summary>
class SpriteComponent : public Component
{
	TransformComponent* transform;
	char texture = '@';

public:

	SpriteComponent();
	SpriteComponent(char tex);

	/// <summary>
	/// initialize component
	/// </summary>
	void init() override;

	/// <summary>
	/// Draw logic of entity
	/// </summary>
	void draw() override;
};