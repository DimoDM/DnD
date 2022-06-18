#pragma once
#include"ECS/ECS.h"
#include"BattleSystem.h"

class Game
{
public:

	Game();
	void init(); // initialization state of game // load map, load player and ext.
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