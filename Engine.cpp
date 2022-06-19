#include"Engine.h"

void Engine::run()
{
	switch (gameStage)
	{
	case stageMainMenu: gameStage = (GameStage)mainMenu->select();
		break;
	case stageStartGame: gameController->startGame();
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
