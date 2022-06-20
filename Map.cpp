#include"Map.h"
#include<fstream>
#include"TextureManager.h"
#include"ECS/Components.h"
#include"Game.h"
#include"generateFreeVector2D.h"
using namespace std;
Map::Map(Manager& m) : manager(m)
{
	width = 10;
	height = 10;
}

void Map::loadMap(const char* path)
{
	char c;
	std::ifstream mapFile;
	mapFile.open(path);

	int lvl;
	mapFile >> width;
	mapFile >> height;
	mapFile >> lvl;
	mapFile.get();

	mapFile >> exitX;
	mapFile >> exitY;
	mapFile.get();

	int numOfMonsters;
	int numOfTreasures;

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

	mapFile.get(); // skip empty line
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			mapFile.get(c);
			//cout << c;
			if (c == '1') addCollider(x, y);
		}
		mapFile.get(); // skip new line
		//cout << endl;
	}

	for (int i = 0; i < numOfMonsters; i++) addMonster(lvl);
	for (int i = 0; i < numOfTreasures; i++) addTreasure(lvl);


	mapFile.close();
}

void Map::addTile(int xPos, int yPos, const char tex)
{
	Entity& tile(manager.addEntity());
	tile.addComponent<TileComponent>(xPos, yPos, tex);
	tile.addGroup(Game::groupTiles);
}

void Map::addCollider(int xPos, int yPos)
{
	Entity& tile(manager.addEntity());
	tile.addComponent<ColliderComponent>(xPos, yPos);
	tile.addGroup(Game::groupTiles);
}

void Map::addMonster(int lvl)
{
	Entity& monster(manager.addEntity());
	monster.addComponent<MonsterAIComponent>(manager.getGroup(Game::groupPlayer));
	monster.addComponent<SpriteComponent>('M');
	monster.addComponent<CombatComponent>();
	int health = 50 + (10 * lvl);
	int mana = 20 + (10 * lvl);
	int strenght = 30 + (10 * lvl);
	monster.addComponent<StatsComponent>(health, mana, strenght, lvl, 0, lvl);
	monster.addGroup(Game::groupEnemy);
}

void Map::addTreasure(int lvl)
{
	Entity& treasure(manager.addEntity());
	treasure.addComponent<TreasureComponent>(lvl);
	treasure.addGroup(Game::groupTreasures);
}
