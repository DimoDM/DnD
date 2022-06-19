#pragma once
#include"../ConsoleViewer.h"
#include"../Menu.h"
#include"../Game.h"

//source:
//https://www.delftstack.com/howto/cpp/how-to-get-list-of-files-in-a-directory-cpp/
//https://stackoverflow.com/questions/48312460/c17-filesystem-is-not-a-namespace-name
//https://en.cppreference.com/w/cpp/experimental/fs/path
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING 1
#if __cplusplus < 201703L// If the version of C++ is less than 17
// It was still in the experimental:: namespace
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#else
#include <filesystem>
namespace fs = std::filesystem;
#endif

class GameController {



	const char* fileDir = "../data";
	String strVal = "";
	//const char* raceOptions[3] = { "Human", "Mage", "Warrior" };
	//const Menu* raceMenu = new Menu("SelectRace: ", raceOptions, 3, ConsoleViewer::getInstance());

	ConsoleViewer* viewer = nullptr;
	Game* game = nullptr;

	//void loadPlayerFromFile();
	const String getFileNameFromPath(fs::path path);
	const String& selectOption(const char* directory, const char* title);
	const String& selectPlayer();
	const String& selectMap();
	void loadPlayer(int& x, int& y, Optional<Weapon>& w, Optional<Armor>& a, Optional<Spell>& s, int& health, int& mana, int& strenght, String& name);


public:

	GameController(ConsoleViewer* consoleViewer);
	void startGame();
};