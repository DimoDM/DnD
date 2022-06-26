#include"Engine.h"
#include"Models/Items/ItemsList.h"
#include"Views/BattleView.h"
#include"Views/GameView.h"

/// <summary>
/// handle program stages of work
/// </summary>
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
	deleteItems();
	BattleView::getInstance()->free();
	GameView::getInstance()->free();
	ConsoleViewer::getInstance()->free();
}
