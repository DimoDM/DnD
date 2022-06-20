#pragma once
#include"../../Structures/String.h"
#include<iostream>


struct Item
{
private:
	const char* convertTypeToString(int t) const;

public:
	int id;
	String name;
	int type;

	Item(const int i, const String& n, const int t);

	virtual Item* clone() const = 0;

	virtual const String itemToString() const;

	virtual void save(std::ofstream& stream);
	virtual void load(std::ifstream& stream);

	virtual ~Item() {}
};

static enum Type {
	TypeWeapon = 0,
	TypeArmor,
	TypeSpell,
	TypeEmpty
};