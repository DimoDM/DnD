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
	Spell(const Spell& s) : Item(s.id, s.name, s.type) {
		dmg = s.dmg;
		cost = s.cost;
	}
	Spell() : dmg(0), cost(0), Item(0, "", Type::TypeSpell) {}

	Item* clone() const override {
		Item* newObj = new Spell(*this);
		return newObj;
	}

	void use() override {
	}

	void save(std::ofstream& stream) override {
		Item::save(stream);
		stream.write((const char*)&dmg, sizeof(int));
		stream.write((const char*)&cost, sizeof(int));
	}
	void load(std::ifstream& stream) override {
		Item::load(stream);
		stream.read((char*)&this->dmg, sizeof(int));
		stream.read((char*)&this->cost, sizeof(int));
	}

	const const String itemToString() const override {
		String item(Item::itemToString());
		item += " dmg: ";
		item += dmg;
		item += " cost: ";
		item += cost;
		return item;
	}
};