#pragma once
#include"Structures/String.h"

class Item
{
	int id;
	int durability;
	String name;
	int tag;

	Item(const char* n, const int i, const int d, const int t) {
		id = i;
		durability = d;
		tag = t;
		name = n;
	}

	virtual Item* clone() const = 0;

	virtual void use() = 0;

	virtual ~Item() {}
};