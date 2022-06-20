#include"../SaveInFileComponent.h"
#include<fstream>
#include<iostream>
#include"../../../Service/FileManager.h"

SaveInFileComponent::SaveInFileComponent() : Component() {
	type = 10;
}

/// <summary>
/// ...get already initialized compomponents for player
/// </summary>
void SaveInFileComponent::init()
{
	transform = &entity->getComponent<TransformComponent>();
	sprite = &entity->getComponent<SpriteComponent>();
	inventory = &entity->getComponent<InventoryComponent>();
	stats = &entity->getComponent<StatsComponent>();
	player = &entity->getComponent<PlayerComponent>();

}

/// <summary>
/// ...save player to binary file named to him
/// </summary>
void SaveInFileComponent::save()
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

/// <summary>
/// ...save player's position in binary file
/// </summary>
/// <param name="stream"></param>
void SaveInFileComponent::savePosition(std::ofstream& stream)
{
	int x = transform->getX();
	int y = transform->getY();
	stream.write((const char*)&x, sizeof(int));
	stream.write((const char*)&y, sizeof(int));
}

/// <summary>
/// save player's inventar in binary file
/// </summary>
/// <param name="stream"></param>
void SaveInFileComponent::saveInventory(std::ofstream& stream)
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

/// <summary>
/// save player's stats in binary file
/// </summary>
/// <param name="stream"></param>
void SaveInFileComponent::saveStats(std::ofstream& stream)
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

/// <summary>
/// save player's name in binary file
/// </summary>
/// <param name="stream"></param>
void SaveInFileComponent::saveName(std::ofstream& stream)
{
	size_t lenght = strlen(player->getName());
	stream.write((const char*)&lenght, sizeof(size_t));
	stream.write(player->getName(), lenght);
}

