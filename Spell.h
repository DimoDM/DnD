#pragma once
#include"Item.h"
class Spell : public Item {
public:

	int dmg;
	int cost;

	Spell(const int id, const char* name, const int d, const int c) : Item(id, name, Type::TypeSpell) {
		dmg = d;
		cost = c;
	}

	Item* clone() const override {
		Item* newObj = new Spell(*this);
		return newObj;
	}

	void use() override {
	}

	const char* itemToString() const override {
		String item(Item::itemToString());
		item += " dmg: ";
		item += dmg;
		item += " cost: ";
		item += cost;
		return item.c_str();
	}
};