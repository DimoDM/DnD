#include"Game.h"
#include"ConsoleViewer.h"

Game::Game()
{
}

void Game::init()
{
	ConsoleViewer::createInstance(10, 10);
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
