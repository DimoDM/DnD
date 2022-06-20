#include"../GameController.h"
#include"../../Service/FileManager.h"

GameController::GameController(ConsoleViewer* consoleViewer)
{
	viewer = consoleViewer;
	gameOverMenu = new Menu("You died. Start again?", continueOptions, 2, viewer);
	nextLvlMenu = new Menu("Congratulations! Will you continue the game?", continueOptions, 2, viewer);

}

void GameController::startGame()
{
	String playerName = "./data/";
	playerName += selectPlayer();
	playerName += ".txt";

	int completedLevels;
	std::ifstream file;
	FileManager::openFile(file, playerName.c_str(), std::ios::binary);
	file.read((char*)&completedLevels, sizeof(int));
	file.close();

	String mapFile = "./assets/"; 
	mapFile += selectMap(completedLevels);
	mapFile += ".txt";

	playGame(playerName.c_str(), mapFile.c_str());

}

GameController::~GameController()
{
	delete gameOverMenu;
	delete nextLvlMenu;
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
		game.init(x, y, w, a, s, health, mana, strenght, level, xp, completedLevels, name.c_str(), mapFile, gameStage);
		w.setData(Weapon());
		a.setData(Armor());
		s.setData(Spell());
		while (gameStage == GameStage::stagePlay) {
			game.update();
			game.draw();
		}
	}
	int choice;
	switch (gameStage)
	{
	case stageDeath:
		choice = gameOverMenu->select();
		if (!choice) {
			playGame(playerFile, mapFile);
		}
		else return;
		break;
	case stageNextLvl:
		choice = nextLvlMenu->select();
		if (!choice) playGame(playerFile, getNextMapFile(mapFile).c_str());
		break;
	default:
		break;
	}

	gameStage = GameStage::stagePlay;

}

const String GameController::getNextMapFile(const char* mapFile) {
	String newMapFile(mapFile);
	char mf[100];
	for (int i = 0; i < newMapFile.getSize(); i++)
		mf[i] = newMapFile.c_str()[i];
	mf[newMapFile.getSize()] = '\0';
	if(mf[9] + 1 <= '4') mf[9] += 1;
	newMapFile = "";
	newMapFile += mf;
	return newMapFile;
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
	FileManager::openFile(file, playerFile, std::ios::binary);
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
	pName[lenght] = '\0';
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
	file.close();
}
