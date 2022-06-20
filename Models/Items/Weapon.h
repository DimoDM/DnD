#pragma once
#include"Item.h"

class Weapon : public Item {
public:

	int dmg;

	Weapon(const int id, const char* name, const int d);

	Weapon(const Weapon& w) : Item(w.id, w.name, w.type);

	Weapon();

	Item* clone() const override;

	void save(std::ofstream& stream) override;
	void load(std::ifstream& stream) override;

	const String itemToString() const override;
};