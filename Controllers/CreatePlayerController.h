#pragma once
#include"../Service/Menu.h"
#include"../Views/ConsoleViewer.h"

/// <summary>
/// Controller witch create player
/// </summary>
class CreatePlayerController
{
	const char* fileDir = "../data";
	const char* raceOptions[3] = { "Human", "Mage", "Warrior" };
	const Menu* raceMenu = new Menu("Select Race: ", raceOptions, 3, ConsoleViewer::getInstance());

	ConsoleViewer* viewer = nullptr;

public:
	CreatePlayerController( ConsoleViewer* consoleViewer);
	/// <summary>
	/// initialize player parameters and save them to file
	/// </summary>
	void createPlayer();
};