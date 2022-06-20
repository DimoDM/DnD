#pragma once
#include"ECS/ECS.h"
class Map
{
	int width;
	int height;
	int exitX;
	int exitY;
	const char* mapFilePath;
	Manager& manager;
	
public:

	Map(Manager& m);

	void loadMap(const char* path);
	void addTile(int xPos, int yPos, const char tex);
	void addCollider(int xPos, int yPos);
	void addMonster(int lvl);
	void addTreasure(int lvl);

	const int getExitX() const;
	const int getExitY() const;
	const int getWidth() const;
	const int getHeight() const;

	~Map() {}
};
