#include"Game.h"
#include"ConsoleViewer.h"
#include"Map.h"
#include"ECS/Components.h"

Game::Game()
{
}

void Game::init()
{
	ConsoleViewer::createInstance(10, 10);
	Map map(manager);
	map.loadMap("assets/maze10x10.txt");

	Entity& player(manager.addEntity());
	player.addComponent<KeyboardComponent>();
	player.addComponent<TransformComponent>();
	player.addComponent<SpriteComponent>();
	player.addComponent<InventoryComponent>();
	player.addGroup(groupPlayer);
	
	Entity& monster(manager.addEntity());
	monster.addComponent<TransformComponent>(8, 8);
	monster.addComponent<SpriteComponent>('M');
	monster.addComponent<MonsterAIComponent>(manager.getGroup(groupPlayer));
}

void Game::update()
{
	manager.update();
}

void Game::draw()
{
	manager.draw();
	ConsoleViewer::getInstance()->print();
}
