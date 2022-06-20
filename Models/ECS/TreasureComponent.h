#pragma once
#include"ECS.h"
#include"TileComponent.h"
#include"../generateFreeVector2D.h"
#include"../Structures/Vector2D.h"
#include"../ItemsList.h"

class TreasureComponent : public Component
{

	TileComponent* tile;
	Item* item = nullptr;
	Vector2D pos = {0, 0};
	int lvl;

public:

	TreasureComponent() : Component() {
		type = 12;
	}

	TreasureComponent(int l) : Component() {
		type = 12;
		lvl = l;
	}


	void init() override {
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

	Item* getItem() const {
		return item;
	}
	void setItem(const Item* i) {
		if (i == item) return;
		delete item;
		item = nullptr;
		if(i != nullptr) item = i->clone();
	}
	void setItem(Weapon& weapon) {
		delete item;
		item = weapon.clone();
	}
	void setItem(Armor& armor) {
		delete item;
		item = armor.clone();
	}
	void setItem(Spell& spell) {
		delete item;
		item = spell.clone();
	}
	void setItem() {
		delete item;
		item = nullptr;
	}

	const Vector2D& getPos() const {
		return pos;
	}

	~TreasureComponent() {
		delete item;
	}


};