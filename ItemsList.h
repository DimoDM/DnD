#pragma once
#include "Item.h"
#include"Armor.h"
#include"Weapon.h"
#include"Empty.h"
#include"Spell.h"


static Item* items[7] = {
		{ new Empty() },
		{ new Weapon(1, "Wooden sword", 3) },
		{ new Weapon(2, "Dragon Slayer", 30) },
		{ new Spell(3, "Fileball", 25, 5) },
		{ new Armor(4, "Wood Armor", 5) },
		{ new Armor(5, "Chain Armor", 10) },
		{ new Armor(6, "DragonSkin Armor", 15) }
};

static void deleteItems() {
	for (int i = 0; i < 7; i++) {
		delete items[i];
	}
	delete[] items;
}