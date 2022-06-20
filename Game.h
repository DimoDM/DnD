#pragma once
#include"ECS/ECS.h"
#include"BattleSystem.h"
#include"Structures/Optional.h"
#include"ItemsList.h"
#include"FindTreasureSystem.h"
#include"NextLevelSystem.h"
#include"GameStages.h"

class Game
{
public:

	Game();
	void init(int x, int y, Optional<Weapon> w, Optional<Armor> a, Optional<Spell> s, int health, int mana, int strenght, int level, int xp, int completedLevels, const char* name, const char* mapFile, GameStage& stage); // initialization state of game // load map, load player and ext.
	//void init();
	void update(); // do movement and logic of game
	void draw(); // draw state of game when we see results from update state

	static enum Group {
		groupPlayer,
		groupEnemy,
		groupTiles,
		groupTreasures
	};

	bool isRunning() {
		return _isRunning;
	}

	~Game();

private:
	bool _isRunning;
	Manager manager;
	BattleSystem* battleSys = nullptr;
	FindTreasureSystem* findTreasureSys = nullptr;
	NextLevelSystem* lvlSys = nullptr;
	GameStage* gameStage = nullptr;
};