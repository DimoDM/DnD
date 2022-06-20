#include"../Map.h"
#include<fstream>
#include"../TextureManager.h"
#include"../../Models/ECS/ECS.h"
#include"../Game.h"
#include"../../Models/ECS/CombatComponent.h"
#include"../../Models/ECS/StatsComponent.h"
#include"../../Models/ECS/MonsterAiComponent.h"
#include"../../Models/ECS/SpriteComponent.h"
#include"../RandomValues.h"
using namespace std;
Map::Map(Manager& m)
{
	manager = &m;
	width = 10;
	height = 10;
}

void Map::loadDimentions(const char* path) 
{
	std::ifstream mapFile;
	mapFile.open(path);

	mapFile >> width;
	mapFile >> height;
	mapFile >> lvl;
	mapFile.get();
	mapFile.close();
}


void Map::loadMap(const char* path)
{
	char c;
	std::ifstream mapFile;
	mapFile.open(path);

	mapFile >> width;
	mapFile >> height;
	mapFile >> lvl;
	mapFile.get();

	mapFile >> exitX;
	mapFile >> exitY;
	mapFile.get();

	mapFile >> numOfMonsters;
	mapFile >> numOfTreasures;
	mapFile.get();

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			mapFile.get(c);
			addTile(x, y, c);
		}
		mapFile.get(); // skip new line
	}

	mapFile.close();
}

void Map::loadEntites()
{
	for (int i = 0; i < numOfMonsters; i++) addMonster(lvl);
	for (int i = 0; i < numOfTreasures; i++) addTreasure(lvl);

}

void Map::addTile(int xPos, int yPos, const char tex)
{
	Entity& tile(manager->addEntity());
	tile.addComponent<TileComponent>(xPos, yPos, tex);
	tile.addGroup(Game::groupTiles);
}

void Map::addMonster(int lvl)
{
	Entity& monster(manager->addEntity());
	int health = 50 + (10 * (lvl - 1));
	int mana = 20 + (10 * (lvl - 1));
	int strenght = 20 + (10 * (lvl - 1));
	monster.addComponent<MonsterAIComponent>(manager->getGroup(Game::groupPlayer));
	monster.addComponent<SpriteComponent>('M');
	monster.addComponent<StatsComponent>(health, mana, strenght, lvl, 0, lvl);
	monster.addComponent<CombatComponent>();
	monster.addGroup(Game::groupEnemy);
}

void Map::addTreasure(int lvl)
{
	Entity& treasure(manager->addEntity());
	treasure.addComponent<TreasureComponent>(lvl);
	treasure.addGroup(Game::groupTreasures);
}

const int Map::getExitX() const
{
	return exitX;
}

const int Map::getExitY() const
{
	return exitY;
}

const int Map::getWidth() const
{
	return width;
}

const int Map::getHeight() const
{
	return height;
}

const int Map::mapLvl() const
{
	return lvl;
}
