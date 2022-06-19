#pragma once
#include"../Menu.h"

class CreatePlayerController
{
	const char* fileDir = "../data";
	const char* raceOptions[3] = { "Human", "Mage", "Warrior" };
	const Menu* raceMenu = new Menu("SelectRace: ", raceOptions, 3, ConsoleViewer::getInstance());

	ConsoleViewer* viewer = nullptr;

	//const bool isValidName(const char* name) const;
public:
	CreatePlayerController( ConsoleViewer* consoleViewer);
	const bool isValidName(const char* name) const;
	void createPlayer();
};