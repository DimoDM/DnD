#include"Game.h"
#include"GameView.h"
#include"Map.h"
#include"ECS/Components.h"


Game::Game()
{
}

void Game::init(int x, int y, Optional<Weapon> w, Optional<Armor> a, Optional<Spell> s, int health, int mana, int strenght, const char* name, const char* mapFile)
{
	GameView::createInstance(10, 10);
	Map map(manager);
	map.loadMap(mapFile);

	Entity& player(manager.addEntity());
	player.addComponent<KeyboardComponent>();
	player.addComponent<TransformComponent>(x, y);
	player.addComponent<SpriteComponent>();
	player.addComponent<InventoryComponent>(w, a, s);
	player.addComponent<StatsComponent>(health, mana, strenght);
	player.addComponent<CombatComponent>();
	player.addGroup(groupPlayer);

	Entity& monster(manager.addEntity());
	monster.addComponent<MonsterAIComponent>(manager.getGroup(groupPlayer));
	monster.addComponent<SpriteComponent>('M');
	monster.addComponent<CombatComponent>();
	monster.addComponent<StatsComponent>();
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
