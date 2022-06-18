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
					return true;
				}
			}
		}
		player = nullptr;
		monster = nullptr;
		return false;
	}

	void battle() {
		while (listenForBattle()) {
			cout << "battle" << endl;
			draw();
			update();
		}
	}

private:
	void update() {
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
			player->getComponent<StatsComponent>().takeDamage(monster->getComponent<CombatComponent>().getDmgFromLastAttack());
			BattleView::getInstance()->print("Player's health: ");
			BattleView::getInstance()->println(String(player->getComponent<StatsComponent>().getHealth()).c_str());
		}
		playerMove = !playerMove;
	}

	void draw() {
		BattleView::getInstance()->print();
		system("pause");
	}
};