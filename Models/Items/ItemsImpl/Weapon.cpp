//#include"../Weapon.h"

/// <summary>
/// reason to use inline:
/// https://docs.microsoft.com/en-us/cpp/error-messages/tool-errors/linker-tools-error-lnk2005?f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(LNK2005)%26rd%3Dtrue&view=msvc-170
/// </summary>
/// <param name="id"></param>
/// <param name="name"></param>
/// <param name="d"></param>

//inline Weapon::Weapon(const int id, const char* name, const int d) : Item(id, name, Type::TypeWeapon) {
//	dmg = d;
//}
//
//inline Weapon::Weapon(const Weapon& w) : Item(w.id, w.name, w.type) {
//	dmg = w.dmg;
//}
//
//inline Weapon::Weapon() : dmg(0), Item(0, "", Type::TypeWeapon) {}
//
//inline Item* Weapon::clone() const {
//	Item* newObj = new Weapon(*this);
//	return newObj;
//}
//
//
//inline void Weapon::save(std::ofstream& stream) {
//	Item::save(stream);
//	stream.write((const char*)&dmg, sizeof(int));
//}
//inline void Weapon::load(std::ifstream& stream) {
//	Item::load(stream);
//	stream.read((char*)&this->dmg, sizeof(int));
//}
//
//inline const String Weapon::itemToString() const {
//	String item = Item::itemToString();
//	item += " dmg: ";
//	item += (size_t)dmg;
//	return item;
//}