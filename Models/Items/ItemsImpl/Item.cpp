#include"../Item.h"

const char* Item::convertTypeToString(int t) const {

	switch (t) {
	case 0: return "Weapon";
	case 1: return "Armor";
	case 2: return "Spell";
	case 3: return "";
	default: return "";
	}
}

Item::Item(const int i, const String& n, const int t) {
	id = i;
	type = t;
	name = n;
}

const String Item::itemToString() const {
	String item(convertTypeToString(type));
	item += ": ";
	item += name;
	return item;
}

void Item::save(std::ofstream& stream) {
	stream.write((const char*)&id, sizeof(int));
	size_t lenght = strlen(name.c_str());
	stream.write((const char*)&lenght, sizeof(size_t));
	stream.write(name.c_str(), lenght);
}

void Item::load(std::ifstream& stream) {
	size_t lenght;
	char name[100];
	stream.read((char*)&this->id, sizeof(int));
	stream.read((char*)&lenght, sizeof(size_t));
	stream.read((char*)&name, lenght);
	name[lenght] = '\0';
	this->name = name;
}

Item::~Item() {}