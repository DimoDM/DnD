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
			String text = "Weapon: ";
			text += weapon.getData().name;
			(text += " dmg: ").concat(weapon.getData().dmg);
			ConsoleViewer::getInstance()->println(text.c_str());
		}
		if (spell.containsData()) {
			String text = "Spell: ";
			text += spell.getData().name;
			(text += " dmg: ").concat(spell.getData().dmg);
			(text += " cost: ").concat(spell.getData().cost);
			ConsoleViewer::getInstance()->println(text.c_str());
		}
		if (armor.containsData()) {
			String text = "Armor: ";
			text += armor.getData().name;
			(text += " defence: ").concat(armor.getData().defence);
			ConsoleViewer::getInstance()->println(text.c_str());
		}
	}

};