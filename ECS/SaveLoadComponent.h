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

public:

	SaveLoadComponent();

	void init() override;

	void save();
	void load();


};