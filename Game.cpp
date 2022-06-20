#include"Game.h"
#include"GameView.h"
#include"Map.h"
#include"ECS/Components.h"



Game::Game()
{
}

void Game::init(int x, int y, Optional<Weapon> w, Optional<Armor> a, Optional<Spell> s, int health, int mana, int strenght, int level, int xp, int completedLevels, const char* name, const char* mapFile)
{
	GameView::createInstance(10, 10);
	Map map(manager);
	map.loadMap(mapFile);

	Entity& player(manager.addEntity());
	player.addComponent<KeyboardComponent>();
	player.addComponent<TransformComponent>(x, y);
	player.addComponent<SpriteComponent>();
	player.addComponent<InventoryComponent>(w, a, s);
	player.addComponent<StatsComponent>(health, mana, strenght, level, xp, completedLevels);
	player.addComponent<CombatComponent>();
	player.addComponent<PlayerComponent>(name);
	player.addComponent<SaveLoadComponent>();
	player.addGroup(groupPlayer);

	battleSys = new BattleSystem(manager.getGroup(groupPlayer), manager.getGroup(groupEnemy));
	findTreasureSys = new FindTreasureSystem(manager.getGroup(groupPlayer), manager.getGroup(groupTreasures));
	lvlSys = new NextLevelSystem(map.getExitX(), map.getExitY(), manager.getGroup(groupPlayer));

	_isRunning = true;
}

void Game::update()
{
	findTreasureSys->findTreasure(manager);
	if (battleSys->battle() == -1) {
		_isRunning = false;
		return;
	}
	lvlSys->isAtTheExit();
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
	delete findTreasureSys;
	delete lvlSys;
}
