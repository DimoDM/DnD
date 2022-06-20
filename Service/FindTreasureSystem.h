#pragma once
#include"../Models/ECS/ECS.h"
#include"../Structures/Collection.h"
#include"../Models/ECS/InventoryComponent.h"
#include"../Models/ECS/TransformComponent.h"
#include"../Models/ECS/TreasureComponent.h"

class FindTreasureSystem
{

	Collection<Entity>* players = nullptr;
	Collection<Entity>* treasures = nullptr;

	/// <summary>
	/// create option menu title to change item
	/// </summary>
	/// <param name="inventory"></param>
	/// <param name="treasure"></param>
	/// <returns></returns>
	String createMenuTitle(InventoryComponent& inventory, const Item* treasure);

	const bool isPlayerOverTreasure(TransformComponent& transform, TreasureComponent& treasure);

	/// <summary>
	/// swap items with treasure
	/// </summary>
	/// <param name="inventory"></param>
	/// <param name="treasure"></param>
	void selectOptionAndSwap(InventoryComponent& inventory, TreasureComponent& treasure);

public:

	FindTreasureSystem(Collection<Entity>& players, Collection<Entity>& treasures);

	/// <summary>
	/// listen if player is above treasure
	/// </summary>
	void findTreasure();
};