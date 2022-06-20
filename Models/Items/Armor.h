#pragma once
#include"Item.h"
class Armor : public Item {
public:

	int defence;

	Armor(const int id, const char* name, const int def);
	Armor();

	Item* clone() const override;

	void save(std::ofstream& stream) override;
	void load(std::ifstream& stream) override;

	const String itemToString() const override;
};