#include"Game.h"
#include"ConsoleViewer.h"
#include"Map.h"

Game::Game()
{
}

void Game::init()
{
	ConsoleViewer::createInstance(10, 10);
	Map map(manager);
	map.loadMap("assets/maze10x10.txt");
	ConsoleViewer::getInstance()->print();
}

void Game::update()
{
	manager.update();
}

void Game::draw()
{
	manager.draw();
}
