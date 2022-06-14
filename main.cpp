#include<iostream>
#include"ECS/ECS.h"
#include"ECS/Components.h"
int main()
{
	enum Groups {
		groupPlayer = 0,
		groupMonster
	};
	//test for ECS
	Manager manager;
	Entity& player = manager.addEntity();
	player.addGroup(groupPlayer);
	player.addComponent<TestComponent>();
	player.addComponent<TestCMP>(5);

	Entity& monster = manager.addEntity();
	player.addGroup(groupMonster);
	player.addComponent<TestCMP>(100);

	Entity& player2 = manager.addEntity();
	player2.addGroup(groupPlayer);
	player2.addComponent<TestComponent>();
	player2.addComponent<TestCMP>(5);

	for (int i = 0; i < 10; i++) {
		manager.update();
		manager.draw();
	}
	std::cout << std::endl;

	for (int i = 0; i < manager.getGroup(groupPlayer).getSize(); i++) {
		std::cout<<manager.getGroup(groupPlayer)[i]->getComponent<TestCMP>()->test;
	}


	std::cout << "she-wolf";
	return 0;
}