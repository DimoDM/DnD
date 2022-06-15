#pragma once
class Map
{
	int width;
	int height;
	const char* mapFilePath;
public:

	Map();

	void LoadMap(const char* path);
	void AddTile(int xpos, int ypos);

	~Map();
};
