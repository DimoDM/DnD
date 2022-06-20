#pragma once
#include "Item.h"
#include"Armor.h"
#include"Weapon.h"
#include"Empty.h"
#include"Spell.h"

const int SIZEITEMS = 6;

static Item* items[SIZEITEMS] = {
		{ new Weapon(0, "Wooden sword", 10) },
		{ new Weapon(1, "Dragon Slayer", 30) },
		{ new Spell(2, "Fileball", 40, 5) },
		{ new Armor(3, "Wood Armor", 5) },
		{ new Armor(4, "Chain Armor", 10) },
		{ new Armor(5, "DragonSkin Armor", 15) }
};

static void deleteItems() {
	for (int i = 0; i < SIZEITEMS; i++) {
		delete items[i];
	}
	delete[] items;
}