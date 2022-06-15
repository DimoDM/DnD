#include"Game.h"
#include"ConsoleViewer.h"
#include"Map.h"

Game::Game()
{
}

void Game::init()
{
	ConsoleViewer::createInstance(10, 10);
	ConsoleViewer::getInstance()->print();
	Map map(manager);
	map.LoadMap("assets/maze10x10.txt");
}

void Game::update()
{
	manager.update();
}

void Game::draw()
{
	manager.draw();
}
