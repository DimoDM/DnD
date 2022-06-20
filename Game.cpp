#include"Game.h"
#include"GameView.h"
#include"Map.h"
#include"ECS/Components.h"
#include"GameStages.h"


Game::Game()
{
}

void Game::init(int x, int y, Optional<Weapon> w, Optional<Armor> a, Optional<Spell> s, int health, int mana, int strenght, int level, int xp, int completedLevels, const char* name, const char* mapFile, GameStage& stage)
{
	Map map(manager);
	map.loadMap(mapFile);

	GameView::createInstance(map.getWidth(), map.getHeight());
	manager.draw();

	map.loadEntites();

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
	gameStage = &stage;
	*gameStage = GameStage::stagePlay;
	_isRunning = true;
}

void Game::update()
{
	findTreasureSys->findTreasure();
	if (battleSys->battle() == -1) {
		*gameStage = GameStage::stageDeath;
		_isRunning = false;
		return;
	}
	if (lvlSys->isAtTheExit()) {
		*gameStage = GameStage::stageNextLvl;
		_isRunning = false;
		return;
	}
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
