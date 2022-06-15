#include<iostream>
#include"ECS/Components.h"
#include"ECS/ECS.h"
int main()
{
	enum Groups {
		groupPlayer = 0,
		groupMonster
	};
	//test for ECS
	Manager manager;
	Entity &player = manager.addEntity();
	
	player.addGroup(groupPlayer);
	player.addComponent<TestComponent>();
	player.addComponent<TestCMP>(5);
	
	Entity &monster = manager.addEntity();;
	monster.addGroup(groupMonster);
	//monster.addComponent<TestCMP>(100);
	monster.addComponent<MonsterComponent>();

	Entity &player2 = manager.addEntity();
	player2.addGroup(groupPlayer);
	player2.addComponent<TestComponent>();
	player2.addComponent<TestCMP>(5);

	std::cout << "calling TestCMP" << std::endl;
	std::cout<<(player2.getComponent<TestCMP>().test);
	player2.update();
	player2.draw();

	for (int i = 0; i < manager.getGroup(groupPlayer).getSize(); i++) {
		manager.getGroup(groupPlayer)[i].update();
		manager.getGroup(groupPlayer)[i].draw();
	}

	for (int i = 0; i < manager.getGroup(groupMonster).getSize(); i++) {
		manager.getGroup(groupMonster)[i].update();
		manager.getGroup(groupMonster)[i].draw();
	}

	std::cout << "she-wolf";
	return 0;
}