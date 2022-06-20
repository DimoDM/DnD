//#include"../Armor.h"
//
//inline Armor::Armor(const int id, const char* name, const int def) : Item(id, name, Type::TypeArmor) {
//	defence = def;
//}
//
//inline Armor::Armor() : defence(0), Item(0, "", Type::TypeArmor) {}
//
//inline Item* Armor::clone() const {
//	Item* newObj = new Armor(*this);
//	return newObj;
//}
//
//inline void Armor::save(std::ofstream& stream) {
//	Item::save(stream);
//	stream.write((const char*)&defence, sizeof(int));
//}
//
//inline void Armor::load(std::ifstream& stream) {
//	Item::load(stream);
//	stream.read((char*)&this->defence, sizeof(int));
//}
//
//inline const String Armor::itemToString() const {
//	String item(Item::itemToString());
//	item += " def: ";
//	item += defence;
//	return item;
//}