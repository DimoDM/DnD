#pragma once
#include"Structures/String.h"

struct Item
{
	int id;
	String name;
	int type;

	Item(const int i, const char* n, const Type t) {
		id = i;
		type = t;
		name = n;
	}

	virtual Item* clone() const = 0;

	virtual void use() = 0;

	virtual ~Item() {}
};

static enum Type {
	TypeWeapon,
	TypeArmor,
	TypeSpell,
	TypeEmpty
};