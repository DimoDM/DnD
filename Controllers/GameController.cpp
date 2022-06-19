#include"GameController.h"


GameController::GameController(ConsoleViewer* consoleViewer)
{
	viewer = consoleViewer;
}

void GameController::startGame()
{
	String playerName = "./data/";
	playerName += selectPlayer();
	playerName += ".txt";
	String mapFile = "./assets/"; 
	mapFile += selectMap();
	mapFile += ".txt";

	int x, y, health, mana, strenght;
	Optional<Weapon> w;
	Optional<Armor> a;
	Optional<Spell> s;
	String name;

	loadPlayer(x, y, w, a, s, health, mana, strenght, name);
	game->init(x, y, w, a, s, health, mana, strenght, name.c_str(), mapFile.c_str());

}

const String GameController::getFileNameFromPath(fs::path path){
	int index = 0;
	char c[100];
	while (strcmp((const char*)(path.filename().c_str() + index), ".")) {
		c[index] = *(const char*)(path.filename().c_str() + index);
		index++;
	}
	c[index] = '\0';
	return c;
}

const String& GameController::selectOption(const char* directory, const char* title)
{
	Vector<String> options;
	for (const auto& entry : fs::directory_iterator("./data/"))
	{
		options.push_back(getFileNameFromPath(entry.path()));
	}
	Menu m(title, options, viewer);
	int choice = m.select();
	strVal = options[choice];
	return strVal;
}

const String& GameController::selectPlayer()
{
	return selectOption("./data/", "Select player: ");
}

const String& GameController::selectMap()
{
	return selectOption("./assets/", "SelectMap: ");
}

void GameController::loadPlayer(int& x, int& y, Optional<Weapon>& w, Optional<Armor>& a, Optional<Spell>& s, int& health, int& mana, int& strenght, String& name)
{
}
