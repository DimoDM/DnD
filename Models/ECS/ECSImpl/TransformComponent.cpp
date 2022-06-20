#include"../TransformComponent.h"
#include"../../../Views/GameView.h"

TransformComponent::TransformComponent() : Component() {
	type = 2;
}
TransformComponent::TransformComponent(int x, int y) : Component() {
	type = 2;
	this->pos.x = x;
	this->pos.y = y;
}

/// <summary>
/// ...component loop logic
/// </summary>
void TransformComponent::update() {
	pos += vel;

	if (GameView::getInstance()->getElementFromGameMap(pos.x, pos.y) == '#'
		|| pos.x >= GameView::getInstance()->getMaxWidth()
		|| pos.y >= GameView::getInstance()->getMaxHeight()) {
		pos -= vel;
	}
}

/// <summary>
/// ...component preparation for draw logic
/// </summary>
void TransformComponent::draw() {
	vel = { 0, 0 };
}

/// <summary>
/// ...getters and setters
/// </summary>
/// <returns></returns>

const int TransformComponent::getX() const {
	return pos.x;
}
const int TransformComponent::getY() const {
	return pos.y;
}

const Vector2D& TransformComponent::getPos() const {
	return pos;
}

void TransformComponent::setVel(int x, int y) {
	if (x < -1 || x > 1 || y < -1 || y > 1) throw new std::exception("invalid move");
	vel = { x, y };
}

void TransformComponent::setPos(int x, int y) {
	if (x < 0 || x > GameView::getInstance()->getMaxWidth() || y < 0 || y > GameView::getInstance()->getMaxHeight()) throw new std::exception("invalid move");
	pos = { x, y };
}