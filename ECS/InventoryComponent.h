#pragma once
#include"ECS.h"
#include"../ConsoleViewer.h"
#include"../ItemsList.h"
#include"../Structures/Optional.h"
#include"../Structures/String.h"

class InventoryComponent : public Component
{

	Optional<Weapon> weapon;
	Optional<Spell> spell;
	Optional<Armor> armor;

public:

	InventoryComponent() : Component() {
		type = 6;
	}

	InventoryComponent(Optional<Weapon> w, Optional<Armor> a, Optional<Spell> s) : Component() {
		type = 6;
		if (w.containsData()) weapon.setData(w.getData());
		if (a.containsData()) armor.setData(a.getData());
		if (s.containsData()) spell.setData(s.getData());
	}

	void init() override {
		if(!weapon.containsData()) weapon.setData(*static_cast<Weapon*>(items[1]));
		if(!spell.containsData()) spell.setData(*static_cast<Spell*>(items[3]));
	}

	void update() override {

	}
	void draw() override {
		if (entity->hasGroup(0)) {
			GameView::getInstance()->println("Inventory: ");
			if (weapon.containsData()) {
				GameView::getInstance()->println(weapon.getData().itemToString().c_str());
			}
			if (spell.containsData()) {
				GameView::getInstance()->println(spell.getData().itemToString().c_str());
			}
			if (armor.containsData()) {
				GameView::getInstance()->println(armor.getData().itemToString().c_str());
			}
		}
	}

	const Optional<Weapon>& getWeapon() const {
		return weapon;
	}

	const Optional<Armor>& getArmor() const {
		return armor;
	}

	const Optional<Spell>& getSpell() const {
		return spell;
	}

	const int getSpellDmg() const {
		if (spell.containsData()) return spell.getData().dmg;
		return 0;
	}

	const int getWeaponDmg() const {
		if (weapon.containsData()) return weapon.getData().dmg;
		return 0;
	}

	const int getSpellCost() const {
		if (spell.containsData()) return spell.getData().cost;
		return 0;
	}

	const String getWeaponInfo() const {
		if (weapon.containsData()) return weapon.getData().itemToString();
		return "";
	}
	const String getArmorInfo() const {
		if (armor.containsData()) return armor.getData().itemToString();

	}
	const String getSpellInfo() const {
		if (spell.containsData()) return spell.getData().itemToString();
	}

};