#include"../Weapon.h"

Weapon::Weapon(const int id, const char* name, const int d) : Item(id, name, Type::TypeWeapon) {
	dmg = d;
}

Weapon::Weapon(const Weapon& w) : Item(w.id, w.name, w.type) {
	dmg = w.dmg;
}

Weapon::Weapon() : dmg(0), Item(0, "", Type::TypeWeapon) {}

Item* Weapon::clone() const {
	Item* newObj = new Weapon(*this);
	return newObj;
}


void Weapon::save(std::ofstream& stream) {
	Item::save(stream);
	stream.write((const char*)&dmg, sizeof(int));
}
void Weapon::load(std::ifstream& stream) {
	Item::load(stream);
	stream.read((char*)&this->dmg, sizeof(int));
}

const String Weapon::itemToString() const {
	String item = Item::itemToString();
	item += " dmg: ";
	item += (size_t)dmg;
	return item;
}