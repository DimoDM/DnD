#include"../InventoryComponent.h"

InventoryComponent::InventoryComponent() : Component() {
	type = 6;
}

InventoryComponent::InventoryComponent(Optional<Weapon>& w, Optional<Armor>& a, Optional<Spell>& s) : Component() {
	type = 6;
	//tried to fix the bug for new players
	//if (w.containsData())weapon.setData(w.getData());
	//else weapon.clear();
	//if (a.containsData())armor.setData(a.getData());
	//else armor.clear();
	//if (s.containsData())spell.setData(s.getData());
	//else spell.clear();

	weapon = w;
	armor = a;
	spell = s;
}

/// <summary>
/// ...set default inventory for player
/// </summary>
void InventoryComponent::init() {
	if (entity->hasGroup(0)) {
		if (!weapon.containsData()) weapon.setData(*static_cast<Weapon*>(items[0]));
		if (!spell.containsData()) spell.setData(*static_cast<Spell*>(items[2]));
		if (!armor.containsData()) armor.clear();
	}
}

/// <summary>
/// ...show us inventory
/// </summary>
void InventoryComponent::draw() {
	if (entity->hasGroup(0)) {
		GameView::getInstance()->println("Inventory: ");
		if (weapon.containsData()) {
			GameView::getInstance()->println(weapon.getData().itemToString().c_str());
		}
		if (spell.containsData()) {
			GameView::getInstance()->println(spell.getData().itemToString().c_str());
		}
		if (armor.containsData()) {
			GameView::getInstance()->println(armor.getData().itemToString().c_str());
		}
	}
}

/// <summary>
/// ...swap item from our inventar with that we use for parameter
/// </summary>
/// <param name="item"></param>
/// <returns></returns>
Item* InventoryComponent::swapItem(Item* item) {
	if (item == nullptr) return nullptr;
	Item* swap = item->clone();
	delete item;
	switch (swap->type)
	{
	case 0: if (weapon.containsData()) { item = weapon.getData().clone(); }
		  else { item = nullptr; } weapon.setData(static_cast<Weapon&>(*swap)); break;
	case 1: if (armor.containsData()) { item = armor.getData().clone(); }
		  else { item = nullptr; } armor.setData(static_cast<Armor&>(*swap)); break;
	case 2: if (spell.containsData()) { item = spell.getData().clone(); }
		  else { item = nullptr; } spell.setData(static_cast<Spell&>(*swap)); break;
	default:
		break;
	}
	return item;
}

/// <summary>
/// ...return item from inventory 
/// </summary>
/// <param name="type"></param>
/// <returns></returns>
const Item* InventoryComponent::getItemByType(int type) const {
	switch (type)
	{
	case 0: if (weapon.containsData()) return (&weapon.getData()); break;
	case 1: if (armor.containsData()) return (&armor.getData()); break;
	case 2: if (spell.containsData()) return (&spell.getData()); break;
	default: return nullptr;
	}
	return nullptr;
}

/// <summary>
/// ...getters and setters
/// </summary>
/// <returns></returns>
const Optional<Weapon>& InventoryComponent::getWeapon() const {
	return weapon;
}

const Optional<Armor>& InventoryComponent::getArmor() const {
	return armor;
}

const Optional<Spell>& InventoryComponent::getSpell() const {
	return spell;
}

const int InventoryComponent::getSpellDmg() const {
	if (spell.containsData()) return spell.getData().dmg;
	return 0;
}

const int InventoryComponent::getWeaponDmg() const {
	if (weapon.containsData()) return weapon.getData().dmg;
	return 0;
}

const int InventoryComponent::getArmorDef() const {
	if (armor.containsData()) return armor.getData().defence;
	return 0;
}

const int InventoryComponent::getSpellCost() const {
	if (spell.containsData()) return spell.getData().cost;
	return 0;
}

const String InventoryComponent::getWeaponInfo() const {
	if (weapon.containsData()) return weapon.getData().itemToString();
	return "";
}
const String InventoryComponent::getArmorInfo() const {
	if (armor.containsData()) return armor.getData().itemToString();
	return "";

}
const String InventoryComponent::getSpellInfo() const {
	if (spell.containsData()) return spell.getData().itemToString();
	return "";
}