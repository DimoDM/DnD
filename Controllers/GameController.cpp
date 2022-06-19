#include"GameController.h"
#include"../Structures/FileManager.h"

GameController::GameController(ConsoleViewer* consoleViewer)
{
	viewer = consoleViewer;
	gameOverMenu = new Menu("You died. Start again?", continueOptions, 2, viewer);
}

void GameController::startGame()
{
	String playerName = "./data/";
	playerName += selectPlayer();
	playerName += ".txt";

	int completedLevels;
	std::ifstream file;
	FileManager::openFile(file, playerName.c_str(), ios::binary);
	file.read((char*)&completedLevels, sizeof(int));
	file.close();

	String mapFile = "./assets/"; 
	mapFile += selectMap(completedLevels);
	mapFile += ".txt";

	playGame(playerName.c_str(), mapFile.c_str());

}

void GameController::playGame(const char* playerFile, const char* mapFile)
{
	{
		Game game;
		int x, y, health, mana, strenght, level, xp, completedLevels;
		Optional<Weapon> w;
		Optional<Armor> a;
		Optional<Spell> s;
		String name;


		loadPlayer(playerFile, x, y, w, a, s, health, mana, strenght, level, xp, completedLevels, name);
		game.init(x, y, w, a, s, health, mana, strenght, level, xp, completedLevels, name.c_str(), mapFile);
		while (game.isRunning()) {
			game.draw();
			game.update();
		}
	}

	int choice = gameOverMenu->select();
	if (!choice) playGame(playerFile, mapFile);
	else return;

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

const String& GameController::selectOption(const char* directory, const char* title, int maxLevels)
{
	Vector<String> options;
	for (const auto& entry : fs::directory_iterator(directory))
	{
		String fName(getFileNameFromPath(entry.path()));
		if (fName.c_str()[0] >= '0' && fName.c_str()[0] <= '9') {
			int fileLevel = fName.c_str()[0] - '0';
			if (fileLevel <= maxLevels)
				options.push_back(fName);
		}
		else options.push_back(fName);
	}
	Menu m(title, options, viewer);
	int choice = m.select();
	strVal = options[choice];
	return strVal;
}

const String& GameController::selectPlayer()
{
	return selectOption("./data/", "Select player: ", 100);
}

const String& GameController::selectMap(int maxLevels)
{
	return selectOption("./assets/", "SelectMap: ", maxLevels);
}

void GameController::loadPlayer(const char* playerFile, int& x, int& y, Optional<Weapon>& w, Optional<Armor>& a, Optional<Spell>& s, int& health, int& mana, int& strenght, int& level, int& xp, int& completedLevels, String& name)
{
	std::ifstream file;
	FileManager::openFile(file, playerFile, ios::binary);
	size_t lenght;

	file.read((char*)&completedLevels, sizeof(int));
	file.read((char*)&level, sizeof(int));
	file.read((char*)&xp, sizeof(int));
	file.read((char*)&health, sizeof(int));
	file.read((char*)&mana, sizeof(int));
	file.read((char*)&strenght, sizeof(int));

	file.read((char*)&lenght, sizeof(size_t));
	char* pName = new char[100];
	file.read(pName, lenght);
	pName[lenght + 1] = '\0';
	name = pName;
	file.read((char*)&x, sizeof(int));
	file.read((char*)&y, sizeof(int));
	bool containsData;
	file.read((char*)&containsData, sizeof(bool));
	if (containsData) {
		Weapon weapon;
		weapon.load(file);
		w.setData(weapon);
	}
	file.read((char*)&containsData, sizeof(bool));
	if (containsData) {
		Armor armor;
		armor.load(file);
		a.setData(armor);
	}
	file.read((char*)&containsData, sizeof(bool));
	if (containsData) {
		Spell spell;
		spell.load(file);
		s.setData(spell);
	}
}
