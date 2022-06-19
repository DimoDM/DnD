#include"Engine.h"

#include<fstream>
#include<iostream>



void Engine::run()
{

	switch (gameStage)
	{
	case stageMainMenu: gameStage = (GameStage)mainMenu->select();
		break;
	case stageCreatePlayer: playerController.isValidName("Dimo");
		break;
	default:
		break;
	}
	run();
}

Engine::~Engine()
{
	delete mainMenu;
}
