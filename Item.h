#pragma once
#include"Structures/String.h"
#include<iostream>


struct Item
{
private:
	const char* convertTypeToString(int t) const {
		switch (t) {
			case Type::TypeWeapon: return "Weapon";
			case Type::TypeArmor: return "Armor";
			case Type::TypeSpell: return "Spell";
			case Type::TypeEmpty: return "";
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

	virtual const char* itemToString() const {
		String item(convertTypeToString(type));
		item += ": ";
		item += name;
		return item.c_str();
	}

	virtual ~Item() {}
};

static enum Type {
	TypeWeapon = 0,
	TypeArmor,
	TypeSpell,
	TypeEmpty
};