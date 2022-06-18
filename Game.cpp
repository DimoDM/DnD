#include"Game.h"
#include"GameView.h"
#include"Map.h"
#include"ECS/Components.h"


Game::Game()
{
}

void Game::init()
{
	GameView::createInstance(10, 10);
	Map map(manager);
	map.loadMap("assets/maze10x10.txt");

	Entity& player(manager.addEntity());
	player.addComponent<KeyboardComponent>();
	player.addComponent<TransformComponent>();
	player.addComponent<SpriteComponent>();
	player.addComponent<InventoryComponent>();
	player.addComponent<StatsComponent>();
	player.addGroup(groupPlayer);
	
	Entity& monster(manager.addEntity());
	monster.addComponent<MonsterAIComponent>(manager.getGroup(groupPlayer));
	monster.addComponent<SpriteComponent>('M');
	monster.addGroup(groupEnemy);

	battleSys = new BattleSystem(manager.getGroup(groupPlayer), manager.getGroup(groupEnemy));
}

void Game::update()
{
	battleSys->battle();
	manager.update();
}

void Game::draw()
{
	manager.draw();
	GameView::getInstance()->print();
}

Game::~Game()
{
	delete battleSys;
}
