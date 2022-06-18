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
			player->getComponent<CombatComponent>().attack();
			monster->getComponent<StatsComponent>().takeDamage(player->getComponent<CombatComponent>().getDmgFromLastAttack());
		}
		else {
			monster->getComponent<CombatComponent>().attack();
			player->getComponent<StatsComponent>().takeDamage(player->getComponent<CombatComponent>().getDmgFromLastAttack());
			system("pause");
		}
		playerMove = !playerMove;
	}

	void draw() {
		BattleView::getInstance()->print();
	}
};