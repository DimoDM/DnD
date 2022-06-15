#pragma once

class Game
{
public:
	Game();
	void init(); // initialization state of game // load map, load player and ext.
	void update(); // do movement and logic of game
	void draw(); // draw state of game when we see results from update state

private:

};