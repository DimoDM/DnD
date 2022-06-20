#pragma once
#include"../../Structures/String.h"
#include<iostream>


struct Item
{
private:
	const char* convertTypeToString(int t) const {
		switch (t) {
		case 0: return "Weapon";
		case 1: return "Armor";
		case 2: return "Spell";
		case 3: return "";
		default: return "";
		}
	}
public:
	int id;
	String name;
	int type;

	Item(const int i, const String& n, const int t) {
		id = i;
		type = t;
		name = n;
	}

	virtual Item* clone() const = 0;

	virtual void use() = 0;

	virtual const String itemToString() const {
		String item(convertTypeToString(type));
		item += ": ";
		item += name;
		return item;
	}

	virtual void save(std::ofstream& stream) {
		stream.write((const char*)&id, sizeof(int));
		size_t lenght = strlen(name.c_str());
		stream.write((const char*)&lenght, sizeof(size_t));
		stream.write(name.c_str(), lenght);
	}
	virtual void load(std::ifstream& stream) {
		size_t lenght;
		char name[100];
		stream.read((char*)&this->id, sizeof(int));
		stream.read((char*)&lenght, sizeof(size_t));
		stream.read((char*)&name, lenght);
		name[lenght] = '\0';
		this->name = name;
	}

	virtual ~Item() {}
};

static enum Type {
	TypeWeapon = 0,
	TypeArmor,
	TypeSpell,
	TypeEmpty
};