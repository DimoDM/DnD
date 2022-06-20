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
		if(!weapon.containsData()) weapon.setData(*static_cast<Weapon*>(items[0]));
		if(!spell.containsData()) spell.setData(*static_cast<Spell*>(items[2]));
		if (!armor.containsData()) armor.clear();
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

	const Item* getItemByType(int type) const {
		switch (type)
		{
		case 0: if (weapon.containsData()) return (&weapon.getData()); break;
		case 1: if (armor.containsData()) return (&armor.getData()); break;
		case 2: if (spell.containsData()) return (&spell.getData()); break;
		default: return nullptr;
		}
		return nullptr;
	}

	Item* swapItem(Item* item) {
		if (item == nullptr) return nullptr;
		Item* swap = item->clone();
		delete item;
		switch (swap->type)
		{
		case 0: if (weapon.containsData()) { item = weapon.getData().clone(); }
			  else { item = nullptr; } weapon.setData(static_cast<Weapon&>(*swap)); break;
		case 1: if (armor.containsData()) { item = armor.getData().clone(); }
			  else { item = nullptr; } armor.setData(static_cast<Armor&>(*swap)); break;
		case 2: if (spell.containsData()) { item = spell.getData().clone(); }
			  else { item = nullptr; } spell.setData(static_cast<Spell&>(*swap)); break;
		default:
			break;
		}
		return item;
	}

	const int getWeaponDmg() const {
		if (weapon.containsData()) return weapon.getData().dmg;
		return 0;
	}

	const int getArmorDef() const {
		if (armor.containsData()) return armor.getData().defence;
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