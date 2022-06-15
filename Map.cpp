#include"Map.h"
#include<fstream>
#include<iostream>
using namespace std;
Map::Map(Manager& m) : manager(m)
{
}

void Map::LoadMap(const char* path)
{
	char c;
	std::ifstream mapFile;
	mapFile.open(path);

	mapFile >> width;
	mapFile >> height;
	mapFile.get();
	cout << endl;
	cout << width << " " << height;
	for (int y = 0; y <= height; y++) {
		for (int x = 0; x < width; x++) {
			mapFile.get(c);
			cout << c;
		}
		cout << endl;
		mapFile.ignore();
	}
	//mapFile.ignore();

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			mapFile.get(c);
			cout << c;
		}
	}

	mapFile.close();
}

void Map::AddTile(int xpos, int ypos)
{
}
