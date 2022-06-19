#pragma once
#include"../Menu.h"

class CreatePlayerController
{

	const char* raceOptions[3] = { "Human", "Mage", "Warrior" };
	const Menu* mainMenu = new Menu("Main menu", raceOptions, 3, ConsoleViewer::getInstance());
public:
	CreatePlayerController();
};