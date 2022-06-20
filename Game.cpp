#include"Game.h"
#include"GameView.h"
#include"Map.h"
#include"ECS/Components.h"

String createTitle(InventoryComponent& inventory, const Item* treasure) {
	String title;
	if (treasure != nullptr) {
		title = "Get ";
		title += treasure->itemToString().c_str();
		title += " in exchange for ";
		if (inventory.getItemByType(treasure->type) != nullptr) title += inventory.getItemByType(treasure->type)->itemToString().c_str();
		else title += "nothing";
	}
	return title;
}

void findTreasure(Manager& manager) {
	String title;
	const char* options[2] = { "Yes", "No" };
	for (int i = 0; i < manager.getGroup(Game::groupPlayer).getSize(); i++) {
		for (int j = 0; j < manager.getGroup(Game::groupTreasures).getSize(); j++)
			if (manager.getGroup(Game::groupPlayer)[i].getComponent<TransformComponent>().getPos()
				== manager.getGroup(Game::groupTreasures)[j].getComponent<TreasureComponent>().getPos()
				&& manager.getGroup(Game::groupPlayer)[i].getIsActive() && manager.getGroup(Game::groupTreasures)[j].getIsActive()) {
				title = createTitle(manager.getGroup(Game::groupPlayer)[i].getComponent<InventoryComponent>(), &*manager.getGroup(Game::groupTreasures)[j].getComponent<TreasureComponent>().getItem());
				Menu m(title.c_str(), options, 2, GameView::getInstance());
				if (!m.select()) {
					Item* swap = manager.getGroup(Game::groupTreasures)[j].getComponent<TreasureComponent>().getItem();
					manager.getGroup(Game::groupPlayer)[i].getComponent<InventoryComponent>().swapItem(swap);
					manager.getGroup(Game::groupTreasures)[j].getComponent<TreasureComponent>().setItem(swap);
				}
				manager.getGroup(Game::groupTreasures)[j].setIsActive(false);
			}
	}
}


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
	player.addGroup(groupPlayer);

	battleSys = new BattleSystem(manager.getGroup(groupPlayer), manager.getGroup(groupEnemy));

	_isRunning = true;
}

void Game::update()
{
	findTreasure(manager);
	if (battleSys->battle() == -1) {
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
}
