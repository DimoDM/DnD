#include"../TreasureComponent.h"

TreasureComponent::TreasureComponent() : Component() {
	type = 12;
}

TreasureComponent::TreasureComponent(int l) : Component() {
	type = 12;
	lvl = l;
}

/// <summary>
/// init TileComponent if one is not added and set random pos
/// </summary>
void TreasureComponent::init() {
	if (!entity->hasComponent<TileComponent>()) {
		Vector2D pos = Random::generateValidCoordinates();
		entity->addComponent<TileComponent>(pos.x, pos.y, 'T');
	}
	tile = &entity->getComponent<TileComponent>();
	pos = { tile->getX(), tile->getY() };
	const int MAXLVL = 5;
	const int MAXINDEXLVL = SIZEITEMS / MAXLVL;
	int index = Random::getRandomNum(MAXINDEXLVL * (lvl - 1), MAXINDEXLVL * (lvl));
	item = items[index]->clone();
}


/// <summary>
/// getters and setters
/// </summary>
/// <returns></returns>
Item* TreasureComponent::getItem() const {
	return item;
}
void TreasureComponent::setItem(const Item* i) {
	if (i == item) return;
	delete item;
	item = nullptr;
	if (i != nullptr) item = i->clone();
}
void TreasureComponent::setItem(Weapon& weapon) {
	delete item;
	item = weapon.clone();
}
void TreasureComponent::setItem(Armor& armor) {
	delete item;
	item = armor.clone();
}
void TreasureComponent::setItem(Spell& spell) {
	delete item;
	item = spell.clone();
}
void TreasureComponent::setItem() {
	delete item;
	item = nullptr;
}

const Vector2D& TreasureComponent::getPos() const {
	return pos;
}


TreasureComponent::~TreasureComponent() {
	delete item;
}