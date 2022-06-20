#include"../SaveInFileComponent.h"
#include<fstream>
#include<iostream>
#include"../../Service/FileManager.h"

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
		Weapon weapon(w.getData());
		weapon.save(stream);
	}
	else {
		containsData = false;
		stream.write((const char*)&containsData, sizeof(bool));
	}
	if (a.containsData()) {
		containsData = true;
		stream.write((const char*)&containsData, sizeof(bool));
		Armor armor(a.getData());
		armor.save(stream);
	}
	else {
		containsData = false;
		stream.write((const char*)&containsData, sizeof(bool));
	}
	if (s.containsData()) {
		containsData = true;
		stream.write((const char*)&containsData, sizeof(bool));
		Spell spell(s.getData());
		spell.save(stream);
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
	int xp = stats->getXp();
	int level = stats->getLevel();
	int completedLevels = stats->getCompletedLevel();

	stream.write((const char*)&completedLevels, sizeof(int));
	stream.write((const char*)&level, sizeof(int));
	stream.write((const char*)&xp, sizeof(int));
	stream.write((const char*)&health, sizeof(int));
	stream.write((const char*)&mana, sizeof(int));
	stream.write((const char*)&strenght, sizeof(int));
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

	saveStats(file);
	saveName(file);
	savePosition(file);
	saveInventory(file);

	file.close();
}
