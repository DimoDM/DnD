#include<iostream>
#include"ECS/Components.h"
#include"ECS/Entity.h"
int main()
{
	enum Groups {
		groupPlayer = 0,
		groupMonster
	};
	//test for ECS
	//Manager manager;
	//Entity player;
	//player.addGroup(groupPlayer);
	//player.addComponent<TestComponent>();
	//player.addComponent<TestCMP>(5);
	//
	//Entity monster;
	//monster.addGroup(groupMonster);
	//monster.addComponent<TestCMP>(100);

	Entity player2;
	player2.addGroup(groupPlayer);
	player2.addComponent<TestComponent>();
	player2.addComponent<TestCMP>(5);

	std::cout<<(player2.getComponent<TestCMP>().test);
	player2.update();
	player2.draw();
	/*
	for (int i = 0; i < 10; i++) {
		player.update();
		player.draw();
		monster.update();
		monster.draw();
	}
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << player2.getComponent<TestCMP>().test << std::endl;
		player2.update();
	}
	*/

	std::cout << "she-wolf";
	return 0;
}