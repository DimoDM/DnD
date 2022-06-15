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

	void LoadMap(const char* path);
	void AddTile(int xpos, int ypos);

	~Map() {}
};
