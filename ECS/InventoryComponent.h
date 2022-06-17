#pragma once
#include"ECS.h"
#include"../ConsoleViewer.h"
#include"../ItemsList.h"
#include"../Structures/Optional.h"
#include"../Structures/String.h"
class InventoryComponent : public Component
{

	Optional<Weapon> weapon;
	Optional<Armor> armor;
	Optional<Spell> spell;

public:

	InventoryComponent() : Component() {
		type = 6;
	}

	void init() override {
		weapon.setData(*static_cast<Weapon*>(items[1]));
		spell.setData(*static_cast<Spell*>(items[3]));
	}

	void update() override {

	}
	void draw() override {
		if (weapon.containsData()) {
			ConsoleViewer::getInstance()->println(weapon.getData().itemToString().c_str());
		}
		if (spell.containsData()) {
			ConsoleViewer::getInstance()->println(spell.getData().itemToString().c_str());
		}
		if (armor.containsData()) {
			ConsoleViewer::getInstance()->println(armor.getData().itemToString().c_str());
		}
	}

};