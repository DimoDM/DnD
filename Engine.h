#pragma once
#include"Menu.h"
#include"ConsoleViewer.h"
#include"GameStages.h"
#include"Controllers/CreatePlayerController.h"
class Engine
{
	const char *mainMenuOptions[3] = { "start game", "create player", "exit" };
	const Menu* mainMenu = new Menu("Main menu", mainMenuOptions , 3, ConsoleViewer::getInstance());

	CreatePlayerController playerController;

public:

	void run();

	~Engine();
};