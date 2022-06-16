#pragma once
#include"Item.h"
class Empty : public Item {
public:

	Empty() : Item(0, "none", Type::TypeEmpty) {}

	Item* clone() const override {
		Item* newObj = new Empty(*this);
		return newObj;
	}

	void use() override {
	}
};