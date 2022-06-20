#include"../Spell.h"

Spell::Spell(const int id, const char* name, const int d, const int c) : Item(id, name, Type::TypeSpell) {
	dmg = d;
	cost = c;
}
Spell::Spell(const Spell& s) : Item(s.id, s.name, s.type) {
	dmg = s.dmg;
	cost = s.cost;
}
Spell::Spell() : dmg(0), cost(0), Item(0, "", Type::TypeSpell) {}

Item* Spell::clone() const {
	Item* newObj = new Spell(*this);
	return newObj;
}

void Spell::save(std::ofstream& stream) {
	Item::save(stream);
	stream.write((const char*)&dmg, sizeof(int));
	stream.write((const char*)&cost, sizeof(int));
}
void Spell::load(std::ifstream& stream) {
	Item::load(stream);
	stream.read((char*)&this->dmg, sizeof(int));
	stream.read((char*)&this->cost, sizeof(int));
}

const const String Spell::itemToString() const {
	String item(Item::itemToString());
	item += " dmg: ";
	item += dmg;
	item += " cost: ";
	item += cost;
	return item;
}