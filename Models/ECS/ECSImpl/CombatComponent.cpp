#include"../CombatComponent.h"
#include"../../../Views/BattleView.h"
#include"../../../Service/RandomValues.h"
#include"../../../Service/Menu.h"
#include"../../../Structures/String.h"
#include"../../../Structures/Vector.h"
#include"../../../Structures/Optional.h"
#include"../../Items/ItemsList.h"

CombatComponent::CombatComponent() : Component() {
	type = 9;
}

/// <summary>
/// ...roll 20d dice to calculate damage from the attack
/// </summary>
/// <returns></returns>
const int CombatComponent::rollDice() const {
	BattleView::getInstance()->print("Rolling dice, result is ");
	int result = Random::getRandomNum(1, 20);
	BattleView::getInstance()->println(String(result).c_str());
	return result;
}

/// <summary>
/// ...initialize inventory if there is no one
/// </summary>
void CombatComponent::init() {
	if (!entity->hasComponent<InventoryComponent>()) {
		Optional<Weapon> w;
		w.clear();
		Optional<Armor> a;
		a.setData(*static_cast<Armor*>(items[4]));
		Optional<Spell> s;
		s.clear();
		entity->addComponent<InventoryComponent>(w, a, s);
	}
	inventory = &entity->getComponent<InventoryComponent>();
	if (!entity->hasComponent<StatsComponent>()) entity->addComponent<StatsComponent>();
	stats = &entity->getComponent<StatsComponent>();
}

void CombatComponent::attack() {

	//const int MAXOPTIONS = 2;

	/// <summary>
	/// ...initialize list for attack options
	/// </summary>
	Vector<String> options;
	if (inventory->getWeaponInfo().getSize() > 1) options.push_back(inventory->getWeaponInfo());
	if (inventory->getSpellInfo().getSize() > 1 && stats->getMana() > inventory->getSpellCost())
		options.push_back(inventory->getSpellInfo());

	/// <summary>
	/// ...check for attacking options
	/// </summary>
	if (options.getSize() > 1) {
		int attack;
		/// <summary>
		/// ...if entity is player we can choose weapon to attack from the menu
		/// </summary>
		if (entity->hasGroup(0)) {
			Menu menu("Choose item for the attack", options, BattleView::getInstance());
			attack = menu.select();
		}
		/// <summary>
		/// ...if entity is not player it's way to attack will be chosen by random
		/// </summary>
		else attack = Random::getRandomNum(0, 1);
		switch (attack)
		{
		case 0: dmg = stats->getStrenght() + inventory->getWeaponDmg(); break;
		case 1: dmg = stats->getStrenght() + inventory->getSpellDmg(); stats->reduceMana(inventory->getSpellCost()); break;
		default:
			break;
		}
	}
	else {
		/// <summary>
		/// ...if we don't have option to choose combat system choose for us with which item we will attack
		/// </summary>
		if (inventory->getSpellDmg() > 0 && stats->getMana() >= inventory->getSpellCost()) {
			dmg = stats->getStrenght() / 5 + inventory->getSpellDmg();
			stats->reduceMana(inventory->getSpellCost());
		}
		else if (inventory->getWeaponDmg() > 0) {
			dmg = stats->getStrenght() + inventory->getWeaponDmg();
		}
		else dmg = stats->getStrenght();
	}
	/// <summary>
	/// ...print mana and re-calculate dealed damage
	/// </summary>
	BattleView::getInstance()->print("Mana: ");
	BattleView::getInstance()->println(String(stats->getMana()).c_str());
	int dice = rollDice();
	dmg -= ((20 - dice) * 8) / 10;
	BattleView::getInstance()->print("Dealed damage is ");
	BattleView::getInstance()->println(String(dmg).c_str());

}

/// <summary>
/// ...get damage from last attack
/// </summary>
/// <returns></returns>
const int CombatComponent::getDmgFromLastAttack() const {
	return dmg;
}