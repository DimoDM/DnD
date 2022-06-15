#pragma once
#include"ECS/ECS.h"
class Map
{
	int width;
	int height;
	const char* mapFilePath;
	Manager& manager;
	
public:

	Map(Manager& m);

	void loadMap(const char* path);
	void addTile(int xPos, int yPos, const char tex);
	void addCollider(int xPos, int yPos);

	~Map() {}
};
