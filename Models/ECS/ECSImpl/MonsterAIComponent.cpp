#include"../MonsterAIComponent.h"

MonsterAIComponent::MonsterAIComponent() : Component() {
	type = 7;
}

MonsterAIComponent::MonsterAIComponent(Collection<Entity>& ps) : Component() {
	type = 7;
	players = &ps;
}

/// <summary>
/// ...Target the closest player to attack
/// </summary>
/// <returns></returns>
const int MonsterAIComponent::getIndexOfTheClosestPlayer() const {

	const Vector2D MonsterPos = transform->getPos();
	int distance = MAXDISTANCE;
	int index;
	for (int i = 0; i < players->getSize(); i++) {
		int curDis = GetDistance::getDistance(MonsterPos, players->getElementByIndex(i)->getComponent<TransformComponent>().getPos());
		if (distance > curDis) {
			distance = curDis;
			index = i;
		}
	}
	return index;
}

/// <summary>
/// ...initialize velocity of wich monster will move 
/// </summary>
/// <param name="monsterPos"></param>
/// <param name="playerPos"></param>
/// <param name="distance"></param>
/// <returns></returns>
const Vector2D MonsterAIComponent::newVel(const Vector2D& monsterPos, const Vector2D& playerPos, int distance) const {
	int disToPlayer[4] = { distance };
	Vector2D vel[4];
	int index = 0;
	vel[0] = { 1, 0 };
	vel[1] = { -1, 0 };
	vel[2] = { 0, 1 };
	vel[3] = { 0, -1 };
	Vector2D mapCoordinates;

	for (int i = 0; i < 4; i++) {
		mapCoordinates = { vel[i].x + monsterPos.x, vel[i].y + monsterPos.y };
		disToPlayer[i] = GetDistance::getDistance(mapCoordinates, playerPos);
		if (mapCoordinates.x > 1 && mapCoordinates.x < 9 && mapCoordinates.y > 1 && mapCoordinates.y < 9)
			if (distance > disToPlayer[i] && GameView::getInstance()->getElementFromGameMap(mapCoordinates.x, mapCoordinates.y) != '#') {
				distance = disToPlayer[i];
				index = i;
			}
	}

	return vel[index];

}


/// <summary>
/// ...initialize transform component with random coordinates if there is no such
/// </summary>
void MonsterAIComponent::init() {
	if (!entity->hasComponent<TransformComponent>()) {
		Vector2D pos = Random::generateValidCoordinates();
		entity->addComponent<TransformComponent>(pos.x, pos.y);
	}
	transform = &entity->getComponent<TransformComponent>();
}

/// <summary>
/// ...move monster
/// </summary>
void MonsterAIComponent::update() {
	const Vector2D MonsterPos = transform->getPos();
	const Vector2D PlayerPos = players->getElementByIndex(getIndexOfTheClosestPlayer())->getComponent<TransformComponent>().getPos();
	const int distanceToPlayer = GetDistance::getDistance(MonsterPos, PlayerPos);
	const Vector2D newVelocity = newVel(MonsterPos, PlayerPos, distanceToPlayer);
	transform->setVel(newVelocity.x, newVelocity.y);

}