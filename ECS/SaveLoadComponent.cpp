#include"SaveLoadComponent.h"
#include<fstream>
#include<iostream>
#include"../Structures/FileManager.h"

void SaveLoadComponent::savePosition(std::ofstream& stream)
{
	int x = transform->getX();
	int y = transform->getY();
	stream.write((const char*)&x, sizeof(int));
	stream.write((const char*)&y, sizeof(int));
}

void SaveLoadComponent::saveWeapon(std::ofstream& stream)
{
	Optional<Weapon> w = inventory->getWeapon();
	stream.write((const char*)&w.getData().id, sizeof(int));
	size_t lenght = strlen(w.getData().name.c_str());
	stream.write((const char*)&lenght, sizeof(size_t));
	stream.write(w.getData().name.c_str(), lenght);
	int damage = w.getData().dmg;
	stream.write((const char*)&damage, sizeof(int));
}

void SaveLoadComponent::saveArmor(std::ofstream& stream)
{
	Optional<Armor> w = inventory->getArmor();
	stream.write((const char*)&w.getData().id, sizeof(int));
	size_t lenght = strlen(w.getData().name.c_str());
	stream.write((const char*)&lenght, sizeof(size_t));
	stream.write(w.getData().name.c_str(), lenght);
	int defence = w.getData().defence;
	stream.write((const char*)&defence, sizeof(int));
}

void SaveLoadComponent::saveSpell(std::ofstream& stream)
{
	Optional<Spell> w = inventory->getSpell();
	stream.write((const char*)&w.getData().id, sizeof(int));
	size_t lenght = strlen(w.getData().name.c_str());
	stream.write((const char*)&lenght, sizeof(size_t));
	stream.write(w.getData().name.c_str(), lenght);
	int damage = w.getData().dmg;
	int mana = w.getData().cost;
	stream.write((const char*)&damage, sizeof(int));
	stream.write((const char*)&mana, sizeof(int));
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
		saveWeapon(stream);
	}
	else {
		containsData = false;
		stream.write((const char*)&containsData, sizeof(bool));
	}
	if (a.containsData()) {
		containsData = true;
		stream.write((const char*)&containsData, sizeof(bool));
		saveArmor(stream);
	}
	else {
		containsData = false;
		stream.write((const char*)&containsData, sizeof(bool));
	}
	if (s.containsData()) {
		containsData = true;
		stream.write((const char*)&containsData, sizeof(bool));
		saveSpell(stream);
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
