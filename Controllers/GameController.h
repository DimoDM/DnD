#pragma once
#include"../ConsoleViewer.h"
#include"../Menu.h"
#include"../Game.h"
#include"../GameStages.h"
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

	String strVal = "";

	ConsoleViewer* viewer = nullptr;

	const char* continueOptions[3] = { "Yes", "No" };
	Menu* gameOverMenu = nullptr;
	Menu* nextLvlMenu = nullptr;

	const String getFileNameFromPath(fs::path path);
	const String& selectOption(const char* directory, const char* title, int maxLevels);
	const String& selectPlayer();
	const String& selectMap(int maxLevels);
	const String getNextMapFile(const char* mapFile);
	void loadPlayer(const char* playerFile, int& x, int& y, Optional<Weapon>& w, Optional<Armor>& a, Optional<Spell>& s, int& health, int& mana, int& strenght, int& level, int& xp, int& completedLevels, String& name);
	void playGame(const char* playerFile, const char* mapFile);

public:

	GameController(ConsoleViewer* consoleViewer);
	void startGame();
	GameStage gameStage = GameStage::stagePlay;

	~GameController();
};