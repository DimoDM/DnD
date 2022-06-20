#pragma once
#include"ECS/ECS.h"
#include"GetDistance.h"
#include"BattleView.h"
#include"ECS/Components.h"
#include"Game.h"
#include"Menu.h"

class BattleSystem
{
	Collection<Entity>* players;
	Collection<Entity>* monsters;

	Entity* player = nullptr;
	Entity* monster = nullptr;

	bool playerMove = true;

public:

	BattleSystem(Collection<Entity>& ps, Collection<Entity>& ms) {
		players = &ps;
		monsters = &ms;
	}

	bool listenForBattle() {
		for (int i = 0; i < players->getSize(); i++) {
			for (int j = 0; j < monsters->getSize(); j++) {
				if (GetDistance::getDistance(players->getElementByIndex(i)->getComponent<TransformComponent>().getPos(),
					monsters->getElementByIndex(j)->getComponent<TransformComponent>().getPos()) <= 1) {
					player = players->getElementByIndex(i);
					monster = monsters->getElementByIndex(j);
					return player->getIsActive() && monster->getIsActive();
				}
			}
		}
		player = nullptr;
		monster = nullptr;
		return false;
	}

	int battle() {

		if (listenForBattle()) {
			int monsterDamage = 0;
			while (player->getComponent<StatsComponent>().getHealth() > 0 && monster->getComponent<StatsComponent>().getHealth() > 0) {
				//cout << "battle" << endl;
				draw();
				monsterDamage += update();
			}
			if (player->getComponent<StatsComponent>().getHealth() <= 0) {
				return -1;
			}
			else if (monster->getComponent<StatsComponent>().getHealth() <= 0) {
				player->getComponent<StatsComponent>().addHealth(monsterDamage / 2);
				player->getComponent<StatsComponent>().addXp(monster->getComponent<StatsComponent>().getLevel());
			}
		}
		return 0;
	}

private:
	int update() {
		int monsterDamage = 0;
		if (playerMove) {
			BattleView::getInstance()->println("Player's turn");
			player->getComponent<CombatComponent>().attack();
			monster->getComponent<StatsComponent>().takeDamage(player->getComponent<CombatComponent>().getDmgFromLastAttack());
			BattleView::getInstance()->print("Monster's health: ");
			BattleView::getInstance()->println(String(monster->getComponent<StatsComponent>().getHealth()).c_str());
		}
		else {
			BattleView::getInstance()->println("Monster's turn");
			monster->getComponent<CombatComponent>().attack();
			monsterDamage = monster->getComponent<CombatComponent>().getDmgFromLastAttack();
			player->getComponent<StatsComponent>().takeDamage(monsterDamage);
			BattleView::getInstance()->print("Player's health: ");
			BattleView::getInstance()->println(String(player->getComponent<StatsComponent>().getHealth()).c_str());
		}
		playerMove = !playerMove;
		return monsterDamage;
	}

	void draw() {
		BattleView::getInstance()->print();
		system("pause");
	}
};