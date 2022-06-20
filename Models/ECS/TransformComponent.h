#pragma once
#include"ECS.h"
#include"../../Structures/Vector2D.h"

/// <summary>
/// ...this component is responsible to storage coordinates of entity and handle it's movement
/// </summary>
class TransformComponent : public Component
{
	Vector2D pos = { 1, 0 };
	Vector2D vel = { 0, 0 };

public:

	TransformComponent();
	TransformComponent(int x, int y);
	/// <summary>
	/// ...component loop logic
	/// </summary>
	void update() override;
	/// <summary>
	/// ...component preparation for draw logic
	/// </summary>
	void draw() override;

	const int getX() const;
	const int getY() const;

	const Vector2D& getPos() const;
	void setVel(int x, int y);

	void setPos(int x, int y);
};