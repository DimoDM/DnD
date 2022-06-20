#pragma once
#include"Item.h"
class Spell : public Item {
public:

	int dmg;
	int cost;

	Spell(const int id, const char* name, const int d, const int c);
	Spell(const Spell& s) : Item(s.id, s.name, s.type);
	Spell();

	Item* clone() const override;

	void save(std::ofstream& stream) override;
	void load(std::ifstream& stream) override;

	const const String itemToString() const override;
};