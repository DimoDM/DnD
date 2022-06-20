#pragma once
#include"../Views/ConsoleViewer.h"
#include"../Service/Menu.h"
#include"../Service/Game.h"
#include"../Models/GameStages.h"
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

	/// <summary>
	/// return name of file
	/// </summary>
	/// <param name="path"></param>
	/// <returns></returns>
	const String getFileNameFromPath(fs::path path);
	/// <summary>
	/// select one of menu's options
	/// </summary>
	/// <param name="directory"></param>
	/// <param name="title"></param>
	/// <param name="maxLevels"></param>
	/// <returns></returns>
	const String& selectOption(const char* directory, const char* title, int maxLevels);
	/// <summary>
	/// select player to play with
	/// </summary>
	/// <returns></returns>
	const String& selectPlayer();
	/// <summary>
	/// select map to play on
	/// </summary>
	/// <param name="maxLevels"></param>
	/// <returns></returns>
	const String& selectMap(int maxLevels);
	/// <summary>
	/// get path of next map file
	/// </summary>
	/// <param name="mapFile"></param>
	/// <returns></returns>
	const String getNextMapFile(const char* mapFile);
	/// <summary>
	/// load player parameters from binary file
	/// </summary>
	/// <param name="playerFile"></param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="w"></param>
	/// <param name="a"></param>
	/// <param name="s"></param>
	/// <param name="health"></param>
	/// <param name="mana"></param>
	/// <param name="strenght"></param>
	/// <param name="level"></param>
	/// <param name="xp"></param>
	/// <param name="completedLevels"></param>
	/// <param name="name"></param>
	void loadPlayer(const char* playerFile, int& x, int& y, Optional<Weapon>& w, Optional<Armor>& a, Optional<Spell>& s, int& health, int& mana, int& strenght, int& level, int& xp, int& completedLevels, String& name);
	/// <summary>
	/// start play game
	/// </summary>
	/// <param name="playerFile"></param>
	/// <param name="mapFile"></param>
	void playGame(const char* playerFile, const char* mapFile);

public:

	GameController(ConsoleViewer* consoleViewer);

	/// <summary>
	/// prepare for play game func
	/// </summary>
	void startGame();
	GameStage gameStage = GameStage::stagePlay;

	~GameController();
};