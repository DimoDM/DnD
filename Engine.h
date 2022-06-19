#pragma once
#include"Menu.h"
#include"ConsoleViewer.h"
#include"GameStages.h"
#include"Controllers/CreatePlayerController.h"
#include"Controllers/GameController.h"
class Engine
{
	const char *mainMenuOptions[3] = { "start game", "create player", "exit" };
	const Menu* mainMenu = new Menu("Main menu", mainMenuOptions , 3, ConsoleViewer::getInstance());

	CreatePlayerController* playerController = new CreatePlayerController(ConsoleViewer::getInstance());
	GameController* gameController = new GameController(ConsoleViewer::getInstance());

public:

	void run();

	~Engine();
};