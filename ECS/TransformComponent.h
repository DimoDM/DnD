#pragma once
#include"ECS.h"
#include"../Structures/Vector2D.h"
#include"../GameView.h"

class TransformComponent : public Component
{
	Vector2D pos = { 1, 0 };
	Vector2D vel = { 0, 0 };

public:

	TransformComponent() : Component() {
		type = 2;
	}
	TransformComponent(int x, int y) : Component() {
		type = 2;
		this->pos.x = x;
		this->pos.y = y;
	}

	void init() override {
	}

	void update() override {
		pos += vel;

		if (GameView::getInstance()->getElementFromGameMap(pos.x, pos.y) == '#'
			|| pos.x >= GameView::getInstance()->getMaxWidth()
			|| pos.y >= GameView::getInstance()->getMaxHeight()) {
			pos -= vel;
		}
	}
	void draw() override {
		vel = { 0, 0 };
	}

	const int getX() const {
		return pos.x;
	}
	const int getY() const {
		return pos.y;
	}

	const Vector2D& getPos() const {
		return pos;
	}

	void setVel(int x, int y) {
		if (x < -1 || x > 1 || y < -1 || y > 1) throw new std::exception("invalid move");
		vel = { x, y };
	}

	void setPos(int x, int y) {
		if (x < 0 || x > GameView::getInstance()->getMaxWidth() || y < 0 || y > GameView::getInstance()->getMaxHeight()) throw new std::exception("invalid move");
		pos = { x, y };
	}
};