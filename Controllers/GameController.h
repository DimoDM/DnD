#pragma once
#include"../ConsoleViewer.h"
#include"../Menu.h"

class GameController {



	const char* fileDir = "../data";
	const char* raceOptions[3] = { "Human", "Mage", "Warrior" };
	const Menu* raceMenu = new Menu("SelectRace: ", raceOptions, 3, ConsoleViewer::getInstance());

	ConsoleViewer* viewer = nullptr;

	void loadPlayerFromFile();


public:
	GameController(ConsoleViewer* consoleViewer);

	void createPlayer();
};