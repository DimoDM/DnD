#pragma once
#include"Structures/String.h"
#include<iostream>


struct Item
{
private:
	const char* convertTypeToString(int t) const {
		switch (t) {
			case 0: return "Weapon";
			case 1: return "Armor";
			case 2: return "Spell";
			case 3: return "";
			default: return "";
		}
	}
public:
	int id;
	String name;
	int type;

	Item(const int i, const char* n, const int t) {
		id = i;
		type = t;
		name = n;
	}

	virtual Item* clone() const = 0;

	virtual void use() = 0;

	virtual const String itemToString() const {
		String item(convertTypeToString(type));
		item += ": ";
		item += name;
		return item;
	}

	virtual ~Item() {}
};

static enum Type {
	TypeWeapon = 0,
	TypeArmor,
	TypeSpell,
	TypeEmpty
};