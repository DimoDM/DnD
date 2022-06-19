#include"Engine.h"

void Engine::run()
{
	switch (gameStage)
	{
	case stageMainMenu: gameController->selectPlayer();
		gameStage = stageMainMenu;
		break;
	case stageCreatePlayer: playerController->createPlayer();
		gameStage = stageMainMenu;
		break;
	case stageExit: return;
	default:
		break;
	}
	run();
}

Engine::~Engine()
{
	delete mainMenu;
	delete playerController;
}
