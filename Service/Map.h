#pragma once
#include"../Models/ECS/ECS.h"
class Map
{
	int width;
	int height;
	int exitX;
	int exitY;
	int numOfMonsters = 0;
	int numOfTreasures = 0;
	int lvl;
	const char* mapFilePath;
	Manager* manager;
	
public:

	Map(Manager& m);

	/// <summary>
	/// load map and create entittes
	/// </summary>
	/// <param name="path"></param>
	void loadMap(const char* path);
	/// <summary>
	/// load all monsters and treasures on map
	/// </summary>
	void loadEntites();
	/// <summary>
	/// add entity with tile component in tile group
	/// </summary>
	/// <param name="xPos"></param>
	/// <param name="yPos"></param>
	/// <param name="tex"></param>
	void addTile(int xPos, int yPos, const char tex);
	/// <summary>
	/// add monster to the map
	/// </summary>
	/// <param name="lvl"></param>
	void addMonster(int lvl);
	/// <summary>
	/// add treasure to the map
	/// </summary>
	/// <param name="lvl"></param>
	void addTreasure(int lvl);

	const int getExitX() const;
	const int getExitY() const;
	const int getWidth() const;
	const int getHeight() const;
	const int mapLvl() const;

	~Map() {}
};
