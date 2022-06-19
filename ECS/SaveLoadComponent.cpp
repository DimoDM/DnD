#include"SaveLoadComponent.h"
#include<fstream>
#include<iostream>
#include"../Structures/FileManager.h"

//source:
//https://www.delftstack.com/howto/cpp/how-to-get-list-of-files-in-a-directory-cpp/
//https://stackoverflow.com/questions/48312460/c17-filesystem-is-not-a-namespace-name
//https://en.cppreference.com/w/cpp/experimental/fs/path
//#include <experimental\filesystem>
//
//using experimental::filesystem::directory_iterator;

void SaveLoadComponent::savePosition(std::ofstream& stream)
{
	int x = transform->getX();
	int y = transform->getY();
	stream.write((const char*)&x, sizeof(int));
	stream.write((const char*)&y, sizeof(int));
}

void SaveLoadComponent::saveInventory(std::ofstream& stream)
{
	Optional<Weapon> w = inventory->getWeapon();
	Optional<Armor> a = inventory->getArmor();
	Optional<Spell> s = inventory->getSpell();
	bool containsData = false;
	if (w.containsData()) {
		containsData = true;
		stream.write((const char*)&containsData, sizeof(bool));
		stream.write((const char*)&w.getData(), sizeof(Weapon));
	}
	else {
		containsData = false;
		stream.write((const char*)&containsData, sizeof(bool));
	}
	if (a.containsData()) {
		containsData = true;
		stream.write((const char*)&containsData, sizeof(bool));
		stream.write((const char*)&a.getData(), sizeof(Armor));
	}
	else {
		containsData = false;
		stream.write((const char*)&containsData, sizeof(bool));
	}
	if (s.containsData()) {
		containsData = true;
		stream.write((const char*)&containsData, sizeof(bool));
		stream.write((const char*)&s.getData(), sizeof(Spell));
	}
	else {
		containsData = false;
		stream.write((const char*)&containsData, sizeof(bool));
	}
}

void SaveLoadComponent::saveStats(std::ofstream& stream)
{
	int health = stats->getHealth();
	int strenght = stats->getStrenght();
	int mana = stats->getMana();

	stream.write((const char*)&health, sizeof(int));
	stream.write((const char*)&strenght, sizeof(int));
	stream.write((const char*)&mana, sizeof(int));
}

void SaveLoadComponent::saveName(std::ofstream& stream)
{
	size_t lenght = strlen(player->getName());
	stream.write((const char*)&lenght, sizeof(size_t));
	stream.write(player->getName(), lenght);
}

SaveLoadComponent::SaveLoadComponent() : Component() {
	type = 10;
}

void SaveLoadComponent::init()
{
	transform = &entity->getComponent<TransformComponent>();
	sprite = &entity->getComponent<SpriteComponent>();
	inventory = &entity->getComponent<InventoryComponent>();
	stats = &entity->getComponent<StatsComponent>();
	player = &entity->getComponent<PlayerComponent>();

}

void SaveLoadComponent::save()
{
	std::ofstream file;
	String name = "data/";
	name += player->getName();
	name += ".txt";
	FileManager::openFile(file, name.c_str(), ios::binary | ios::trunc);

	saveName(file);
	savePosition(file);
	saveInventory(file);
	saveStats(file);

	file.close();
}
