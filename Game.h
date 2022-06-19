#pragma once
#include"ECS/ECS.h"
#include"BattleSystem.h"
#include"Structures/Optional.h"
#include"ItemsList.h"

class Game
{
public:

	Game();
	void init(int x, int y, Optional<Weapon> w, Optional<Armor> a, Optional<Spell> s, int health, int mana, int strenght, const char* name, const char* mapFile); // initialization state of game // load map, load player and ext.
	//void init();
	void update(); // do movement and logic of game
	void draw(); // draw state of game when we see results from update state

	static enum Group {
		groupPlayer,
		groupEnemy,
		groupTiles
	};

	enum GameState {
		statePlay = 0,
		stateBattle
	} gameState = statePlay;


	~Game();

private:
	Manager manager;
	BattleSystem* battleSys = nullptr;
};