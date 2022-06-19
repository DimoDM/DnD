#include"GameController.h"
#include"../Structures/FileManager.h"

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

	loadPlayer(playerName.c_str(), x, y, w, a, s, health, mana, strenght, name);
	game.init(x, y, w, a, s, health, mana, strenght, name.c_str(), mapFile.c_str());
	while (true) {
		game.update();
	}

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
	for (const auto& entry : fs::directory_iterator(directory))
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

void GameController::loadPlayer(const char* playerFile, int& x, int& y, Optional<Weapon>& w, Optional<Armor>& a, Optional<Spell>& s, int& health, int& mana, int& strenght, String& name)
{
	std::ifstream file;
	FileManager::openFile(file, playerFile, ios::binary);
	size_t lenght;
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
		int dmg;
		size_t lenght;
		char name[100];
		int id;
		file.read((char*)&id, sizeof(int));
		file.read((char*)&lenght, sizeof(size_t));
		file.read((char*)&name, lenght);
		name[lenght] = '\0';
		file.read((char*)&dmg, sizeof(int));
		w.setData(Weapon(id, name, dmg));
	}
	file.read((char*)&containsData, sizeof(bool));
	if (containsData) {
		int defence;
		size_t lenght;
		char name[100];
		int type;
		int id;
		file.read((char*)&id, sizeof(int));
		file.read((char*)&lenght, sizeof(size_t));
		file.read((char*)&name, lenght);
		name[lenght] = '\0';
		file.read((char*)&defence, sizeof(int));
		a.setData(Armor(id, name, defence));
	}
	file.read((char*)&containsData, sizeof(bool));
	if (containsData) {
		int dmg;
		int mana;
		size_t lenght;
		char name[100];
		int type;
		int id;
		file.read((char*)&id, sizeof(int));
		file.read((char*)&lenght, sizeof(size_t));
		file.read((char*)&name, lenght);
		name[lenght] = '\0';
		file.read((char*)&dmg, sizeof(int));
		file.read((char*)&mana, sizeof(int));
		s.setData(Spell(id, name, dmg, mana));
	}

	file.read((char*)&health, sizeof(int));
	file.read((char*)&strenght, sizeof(int));
	file.read((char*)&mana, sizeof(int));
}
