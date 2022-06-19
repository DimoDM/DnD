#include"Engine.h"

#include<fstream>
#include<iostream>



void Engine::run()
{
	switch (gameStage)
	{
	case stageMainMenu: gameStage = (GameStage)mainMenu->select();
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
