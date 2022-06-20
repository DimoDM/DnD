#pragma once
#include"ECS.h"
#include"../../Views/GameView.h"
#include"../Items/ItemsList.h"
#include"../../Structures/Optional.h"
#include"../../Structures/String.h"

/// <summary>
/// this component is responcible to handle items in player's inventar
/// </summary>
class InventoryComponent : public Component
{

	/// <summary>
	/// inventory content
	/// </summary>
	Optional<Weapon> weapon;
	Optional<Spell> spell;
	Optional<Armor> armor;

public:

	InventoryComponent();

	InventoryComponent(Optional<Weapon>& w, Optional<Armor>& a, Optional<Spell>& s);
	/// <summary>
	/// ...set default inventory for player
	/// </summary>
	void init() override;
	/// <summary>
	/// ...show us inventory
	/// </summary>
	void draw() override;

	const int getSpellDmg() const;
	/// <summary>
	/// ...return item from inventory 
	/// </summary>
	/// <param name="type"></param>
	/// <returns></returns>
	const Item* getItemByType(int type) const;
	/// <summary>
	/// ...swap item from our inventar with that we use for parameter
	/// </summary>
	/// <param name="item"></param>
	/// <returns></returns>
	Item* swapItem(Item* item);

	const Optional<Weapon>& getWeapon() const;
	const Optional<Armor>& getArmor() const;
	const Optional<Spell>& getSpell() const;

	const int getWeaponDmg() const;
	const int getArmorDef() const;
	const int getSpellCost() const;
	const String getWeaponInfo() const;
	const String getArmorInfo() const;
	const String getSpellInfo() const;

};