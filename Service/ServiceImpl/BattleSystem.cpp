#include"../BattleSystem.h"
#include"../GetDistance.h"
#include"../RandomValues.h"
#include"../../Views/BattleView.h"
#include"../../Models/ECS/CombatComponent.h"
#include"../../Models/ECS/StatsComponent.h"
#include"../../Models/ECS/TransformComponent.h"
#include"../Game.h"
#include"../Menu.h"

/// <summary>
/// ...load collections with players and monsters
/// </summary>
/// <param name="ps"></param>
/// <param name="ms"></param>
BattleSystem::BattleSystem(Collection<Entity>& ps, Collection<Entity>& ms) {
	players = &ps;
	monsters = &ms;
}

/// <summary>
/// check if battle is ready to start
/// </summary>
/// <returns></returns>
bool BattleSystem::listenForBattle() {
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

/// <summary>
/// do battle logic and return value for the result
/// </summary>
/// <returns></returns>
int BattleSystem::battle() {

	if (listenForBattle()) {
		int monsterDamage = 0;
		playerMove = !Random::getRandomNum(0, 1);
		while (player->getComponent<StatsComponent>().getHealth() > 0 && monster->getComponent<StatsComponent>().getHealth() > 0) {
			//cout << "battle" << endl;
			monsterDamage += update();
			draw();
		}
		if (player->getComponent<StatsComponent>().getHealth() <= 0) {
			return -1;
		}
		else if (monster->getComponent<StatsComponent>().getHealth() <= 0) {
			player->getComponent<StatsComponent>().addHealth(monsterDamage / 2);
			player->getComponent<StatsComponent>().addXp(monster->getComponent<StatsComponent>().getLevel());
		}
		player = nullptr;
		monster = nullptr;
		GameView::getInstance()->print();

	}
	return 0;
}

/// <summary>
/// update components needed for battle and do battle logic, return monster dealed damage
/// </summary>
/// <returns></returns>
int BattleSystem::update() {
	int monsterDamage = 0;
	if (playerMove) {
		BattleView::getInstance()->println("Player's turn");
		player->getComponent<CombatComponent>().attack();
		monster->getComponent<StatsComponent>().takeDamage(player->getComponent<CombatComponent>().getDmgFromLastAttack());
		BattleView::getInstance()->print("Monster's health: ");
		if (monster->getComponent<StatsComponent>().getHealth() > 0)
			BattleView::getInstance()->println(String(monster->getComponent<StatsComponent>().getHealth()).c_str());
		else BattleView::getInstance()->println("0");
	}
	else {
		BattleView::getInstance()->println("Monster's turn");
		monster->getComponent<CombatComponent>().attack();
		monsterDamage = monster->getComponent<CombatComponent>().getDmgFromLastAttack();
		player->getComponent<StatsComponent>().takeDamage(monsterDamage);
		BattleView::getInstance()->print("Player's health: ");
		if (player->getComponent<StatsComponent>().getHealth() > 0)
			BattleView::getInstance()->println(String(player->getComponent<StatsComponent>().getHealth()).c_str());
		else BattleView::getInstance()->println("0");
	}
	playerMove = !playerMove;
	return monsterDamage;
}

/// <summary>
/// draw info for events in battle phase
/// </summary>
void BattleSystem::draw() {
	BattleView::getInstance()->print();
	system("pause");
}