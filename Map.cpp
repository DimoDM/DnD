#include"Map.h"
#include<fstream>
#include"TextureManager.h"
#include"ECS/Components.h"
#include"Game.h"
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

	mapFile >> width;
	mapFile >> height;
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
