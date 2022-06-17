#pragma once
#include"Item.h"
class Armor : public Item {
public:

	int defence;

	Armor(const int id, const char* name, const int def) : Item(id, name, Type::TypeArmor) {
		defence = def;
	}

	Item* clone() const override {
		Item* newObj = new Armor(*this);
		return newObj;
	}

	void use() override {
	}

	const char* itemToString() const override {
		String item(Item::itemToString());
		item += " def: ";
		item += defence;
		return item.c_str();
	}
};