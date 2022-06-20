#pragma once
#include"ECS.h"
#include"Components.h"
#include"../../Structures/Vector.h"
#include"../../Structures/String.h"

/// <summary>
/// component that have func to save player's components in binary file
/// </summary>
class SaveInFileComponent : public Component
{
	TransformComponent* transform;
	SpriteComponent* sprite;
	InventoryComponent* inventory;
	StatsComponent* stats;
	PlayerComponent* player;

	Vector<const char*> playerFilesNames;

	/// <summary>
	/// ...save player's position in binary file
	/// </summary>
	/// <param name="stream"></param>
	void savePosition(std::ofstream& stream);
	/// <summary>
	/// save player's inventar in binary file
	/// </summary>
	/// <param name="stream"></param>
	void saveInventory(std::ofstream& stream);
	/// <summary>
	/// save player's stats in binary file
	/// </summary>
	/// <param name="stream"></param>
	void saveStats(std::ofstream& stream);
	/// <summary>
	/// save player's name in binary file
	/// </summary>
	/// <param name="stream"></param>
	void saveName(std::ofstream& stream);

public:

	SaveInFileComponent();

	/// <summary>
	/// ...get already initialized compomponents for player
	/// </summary>
	void init() override;

	/// <summary>
	/// ...save player to binary file named to him
	/// </summary>
	void save();


};