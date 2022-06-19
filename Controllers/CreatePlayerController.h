#pragma once
#include"../Menu.h"

class CreatePlayerController
{
	const char* fileDir = "../data";
	const char* raceOptions[3] = { "Human", "Mage", "Warrior" };
	const Menu* raceMenu = new Menu("Select Race: ", raceOptions, 3, ConsoleViewer::getInstance());

	ConsoleViewer* viewer = nullptr;

public:
	CreatePlayerController( ConsoleViewer* consoleViewer);
	const bool isValidName(const char* name) const;
	void createPlayer();
};