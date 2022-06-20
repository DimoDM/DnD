#pragma once
#include"Service/Menu.h"
#include"Views/ConsoleViewer.h"
#include"Models/EngineStages.h"
#include"Controllers/CreatePlayerController.h"
#include"Controllers/GameController.h"

/// <summary>
/// run all logic of game, main controller and user menu
/// </summary>
class Engine
{
	const char *mainMenuOptions[3] = { "start game", "create player", "exit" };
	const Menu* mainMenu = new Menu("Main menu", mainMenuOptions , 3, ConsoleViewer::getInstance());

	CreatePlayerController* playerController = new CreatePlayerController(ConsoleViewer::getInstance());
	GameController* gameController = new GameController(ConsoleViewer::getInstance());

public:

	/// <summary>
	/// handle program stages of work
	/// </summary>
	void run();

	~Engine();
};