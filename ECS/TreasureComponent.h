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
		const int MAXLVL = 5;
		const int MAXINDEXLVL = SIZEITEMS / MAXLVL;
		int index = Random::getRandomNum(MAXINDEXLVL * (lvl - 1), MAXINDEXLVL * lvl);
		item = items[index]->clone();
	}

	const Item* getItem() const {
		switch (item->type)
		{
		case 0: return dynamic_cast<Weapon*>(item);
		case 1: return dynamic_cast<Armor*>(item);
		case 2: return dynamic_cast<Spell*>(item);
		default: nullptr; break;
		}
	}

	void setItem(Weapon& weapon) {
		delete item;
		item = &weapon;
	}
	void setItem(Armor&& armor) {
		delete item;
		item = &armor;
	}
	void setItem(Spell&& spell) {
		delete item;
		item = &spell;
	}
	void setItem() {
		delete item;
		item = nullptr;
	}

	~TreasureComponent() {
		delete item;
	}


};