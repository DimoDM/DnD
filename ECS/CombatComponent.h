#pragma once
#include"ECS.h"
#include"Components.h"
#include"../Menu.h"
#include"../generateFreeVector2D.h"
#include"../BattleView.h"

class CombatComponent : public Component
{

	InventoryComponent* inventory = nullptr;
	StatsComponent* stats = nullptr;
	int dmg = 0;

	const int rollDice() const {
		BattleView::getInstance()->print("Rolling dice, result is ");
		int result = Random::getRandomNum(1, 20);
		BattleView::getInstance()->println(String(result).c_str());
		return result;
	}

public:

	CombatComponent() : Component() {
		type = 9;
	}

	void attack() {

		//const int MAXOPTIONS = 2;
		Vector<String> options;
		if (inventory->getWeaponInfo().getSize() > 1) options.push_back(inventory->getWeaponInfo());
		if (inventory->getSpellInfo().getSize() > 1) options.push_back(inventory->getSpellInfo());

		if (options.getSize() > 1) {
			int attack;
			if (entity->hasGroup(0)) {
				Menu menu("Choose item for the attack", options, BattleView::getInstance());
				attack = menu.select();
			}
			else attack = Random::getRandomNum(0, 1);
			switch (attack)
			{
			case 0: dmg = stats->getStrenght() + inventory->getWeaponDmg(); break;
			case 1: dmg = stats->getStrenght() + inventory->getSpellDmg(); break;
			default:
				break;
			}
		}
		else {
			dmg = stats->getStrenght() + inventory->getSpellDmg() + inventory->getWeaponDmg();
			stats->reduceMana(inventory->getSpellCost());
			BattleView::getInstance()->print("Mana: ");
			BattleView::getInstance()->println(String(stats->getMana()).c_str());
		}

		int dice = rollDice();
		dmg -= ((20 - dice) * 8) / 10;
		BattleView::getInstance()->print("Dealed damage is ");
		BattleView::getInstance()->println(String(dmg).c_str());

	}

	const int getDmgFromLastAttack() const {
		return dmg;
	}

	void init() override {
		if (!entity->hasComponent<InventoryComponent>()) entity->addComponent<InventoryComponent>();
		inventory = &entity->getComponent<InventoryComponent>();
		if (!entity->hasComponent<StatsComponent>()) entity->addComponent<StatsComponent>();
		stats = &entity->getComponent<StatsComponent>();
	}

	void update() override {}

	void draw() override {
	}
};