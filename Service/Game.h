#pragma once
#include"../Models/ECS/ECS.h"
#include"BattleSystem.h"
#include"FindTreasureSystem.h"
#include"NextLevelSystem.h"
#include"../Models/GameStages.h"

class Game
{
public:

	Game();
	/// <summary>
	/// create player by parameters
	/// initialization state of game // load map, load player and ext.
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="w"></param>
	/// <param name="a"></param>
	/// <param name="s"></param>
	/// <param name="health"></param>
	/// <param name="mana"></param>
	/// <param name="strenght"></param>
	/// <param name="level"></param>
	/// <param name="xp"></param>
	/// <param name="completedLevels"></param>
	/// <param name="name"></param>
	/// <param name="mapFile"></param>
	/// <param name="stage"></param>
	void init(int x, int y, Optional<Weapon> w, Optional<Armor> a, Optional<Spell> s, int health, int mana, int strenght, int level, int xp, int completedLevels, const char* name, const char* mapFile, GameStage& stage);
	/// <summary>
	/// do movement and logic of game
	/// </summary>
	void update();
	/// <summary>
	/// draw state of game when we see results from update state
	/// </summary>
	void draw();

	/// <summary>
	/// groups of entities
	/// </summary>
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