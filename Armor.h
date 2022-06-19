#pragma once
#include"Item.h"
class Armor : public Item {
public:

	int defence;

	Armor(const int id, const char* name, const int def) : Item(id, name, Type::TypeArmor) {
		defence = def;
	}
	Armor() : defence(0), Item(0, "", Type::TypeArmor) {}

	Item* clone() const override {
		Item* newObj = new Armor(*this);
		return newObj;
	}

	void use() override {
	}

	void save(std::ofstream& stream) override {
		Item::save(stream);
		stream.write((const char*)&defence, sizeof(int));
	}
	void load(std::ifstream& stream) override {
		Item::load(stream);
		stream.read((char*)&this->defence, sizeof(int));
	}

	const String itemToString() const override {
		String item(Item::itemToString());
		item += " def: ";
		item += defence;
		return item;
	}
};