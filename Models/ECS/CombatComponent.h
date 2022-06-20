#pragma once
#include"ECS.h"
#include"InventoryComponent.h"
#include"StatsComponent.h"

/// <summary>
/// ...handle entity during battle phase
/// </summary>
class CombatComponent : public Component
{

	InventoryComponent* inventory = nullptr;
	StatsComponent* stats = nullptr;
	int dmg = 0;

	/// <summary>
	/// ...roll 20d dice to calculate damage from the attack
	/// </summary>
	/// <returns></returns>
	const int rollDice() const;

public:

	CombatComponent();
	/// <summary>
	/// ...initialize list for attack options
	/// ...check for attacking options
	/// ...if entity is player we can choose weapon to attack from the menu
	/// ...if entity is not player it's way to attack will be chosen by random
	/// ...if we don't have option to choose combat system choose for us with which item we will attack
	/// ...print mana and re-calculate dealed damage
	/// </summary>
	void attack();

	/// <summary>
	/// ...get damage from last attack
	/// </summary>
	/// <returns></returns>
	const int getDmgFromLastAttack() const;

	/// <summary>
	/// ...initialize inventory if there is no one
	/// </summary>
	void init() override;

};