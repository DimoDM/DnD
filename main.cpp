#include<iostream>
#include"Game.h"
int main()
{
	Game game;
	game.init();
	game.update();
	game.draw();
	std::cout << "she-wolf";
	return 0;
}
