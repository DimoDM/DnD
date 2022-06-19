#pragma once
#include"ECS.h"
#include"Components.h"
#include"../Structures/Vector.h"
#include"../Structures/String.h"

class SaveLoadComponent : public Component
{
	TransformComponent* transform;
	SpriteComponent* sprite;
	InventoryComponent* inventory;
	StatsComponent* stats;
	PlayerComponent* player;

	Vector<const char*> playerFilesNames;

	void savePosition(std::ofstream& stream);
	void saveWeapon(std::ofstream& stream);
	void saveArmor(std::ofstream& stream);
	void saveSpell(std::ofstream& stream);
	void saveInventory(std::ofstream& stream);
	void saveStats(std::ofstream& stream);
	void saveName(std::ofstream& stream);

public:

	SaveLoadComponent();

	void init() override;

	void save();


};