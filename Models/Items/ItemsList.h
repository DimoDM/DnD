#pragma once
#include "Item.h"
#include"Armor.h"
#include"Weapon.h"
#include"Spell.h"

/// <summary>
/// list size
/// </summary>
const int SIZEITEMS = 12;

/// <summary>
/// global list of all items
/// </summary>
static Item* items[SIZEITEMS] = {
		{ new Weapon(0, "Wooden sword", 10)},
		{ new Armor(1, "Wood Armor", 5)},
		{ new Spell(2, "Fileball", 40, 5) },
		{ new Weapon(3, "Dragon Slayer", 30) },
		{ new Armor(4, "DragonSkin Armor", 15) },
		{ new Spell(5, "Lightning Blast", 80, 15) },
		{ new Weapon(6, "Fire Sword", 50) },
		{ new Armor(7, "Chain Armor", 30) },
		{ new Spell(8, "Freeze to death", 100, 25) },
		{ new Weapon(9, "Battle axe", 80) },
		{ new Armor(10, "Black manta", 50) },
		{ new Spell(11, "Flying knifes", 130, 40) },
};

/// <summary>
/// func for deleting list
/// </summary>
static void deleteItems() {
	for (int i = 0; i < SIZEITEMS; i++) {
		delete items[i];
	}
}