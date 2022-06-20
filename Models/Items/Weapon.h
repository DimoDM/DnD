#pragma once
#include"Item.h"
class Weapon : public Item {
public:

	int dmg;

	Weapon(const int id, const char* name, const int d) : Item(id, name, Type::TypeWeapon) {
		dmg = d;
	}

	Weapon(const Weapon& w) : Item(w.id, w.name, w.type) {
		dmg = w.dmg;
	}

	Weapon() : dmg(0), Item(0, "", Type::TypeWeapon) {}

	Item* clone() const override {
		Item* newObj = new Weapon(*this);
		return newObj;
	}

	void use() override {
	}

	void save(std::ofstream& stream) override {
		Item::save(stream);
		stream.write((const char*)&dmg, sizeof(int));
	}
	void load(std::ifstream& stream) override {
		Item::load(stream);
		stream.read((char*)&this->dmg, sizeof(int));
	}

	const String itemToString() const override {
		String item = Item::itemToString();
		item += " dmg: ";
		item += (size_t)dmg;
		return item;
	}
};