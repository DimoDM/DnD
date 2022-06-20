#include"Engine.h"

void Engine::run()
{
	switch (engineStage)
	{
	case stageMainMenu: engineStage = (EngineStage)(mainMenu->select() + 1);
		break;
	case stageStartGame: gameController->startGame(); engineStage = stageMainMenu; break;
	case stageCreatePlayer: playerController->createPlayer();
		engineStage = stageMainMenu;
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
