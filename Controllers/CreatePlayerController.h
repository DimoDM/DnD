#pragma once
#include"../Menu.h"

class CreatePlayerController
{
	const char* fileDir = "../data";
	const char* raceOptions[3] = { "Human", "Mage", "Warrior" };
	const Menu* mainMenu = new Menu("Main menu", raceOptions, 3, ConsoleViewer::getInstance());

	//const bool isValidName(const char* name) const;
public:
	CreatePlayerController();
	const bool isValidName(const char* name) const;
};