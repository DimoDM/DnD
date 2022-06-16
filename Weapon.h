#pragma once
#include"Item.h"
class Weapon : public Item {
public:

	int dmg;

	Weapon(const int id, const char* name, const int d) : Item(id, name, Type::TypeWeapon) {
		dmg = d;
	}

	Item* clone() const override {
		Item* newObj = new Weapon(*this);
		return newObj;
	}

	void use() override {
	}
};