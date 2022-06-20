#include"../FindTreasureSystem.h"
#include"../../Models/Items/ItemsList.h"
#include"../Menu.h"

FindTreasureSystem::FindTreasureSystem(Collection<Entity>& players, Collection<Entity>& treasures) {
	this->players = &players;
	this->treasures = &treasures;
}

/// <summary>
/// listen if player is above treasure
/// </summary>
void FindTreasureSystem::findTreasure() {
	for (int i = 0; i < players->getSize(); i++) {
		for (int j = 0; j < treasures->getSize(); j++)
			if (isPlayerOverTreasure(players->getElementByIndex(i)->getComponent<TransformComponent>(),
				treasures->getElementByIndex(j)->getComponent<TreasureComponent>())) {
				selectOptionAndSwap(players->getElementByIndex(i)->getComponent<InventoryComponent>(),
					treasures->getElementByIndex(j)->getComponent<TreasureComponent>());
			}
	}
}

/// <summary>
/// create option menu title to change item
/// </summary>
/// <param name="inventory"></param>
/// <param name="treasure"></param>
/// <returns></returns>
String FindTreasureSystem::createMenuTitle(InventoryComponent& inventory, const Item* treasure) {
	String title;
	if (treasure != nullptr) {
		title = "Get ";
		title += treasure->itemToString().c_str();
		title += " in exchange for ";
		if (inventory.getItemByType(treasure->type) != nullptr) title += inventory.getItemByType(treasure->type)->itemToString().c_str();
		else title += "nothing";
	}
	return title;
}

const bool FindTreasureSystem::isPlayerOverTreasure(TransformComponent& transform, TreasureComponent& treasure) {
	return transform.getPos() == treasure.getPos() && transform.entity->getIsActive() && treasure.entity->getIsActive();
}

/// <summary>
/// swap items with treasure
/// </summary>
/// <param name="inventory"></param>
/// <param name="treasure"></param>
void FindTreasureSystem::selectOptionAndSwap(InventoryComponent& inventory, TreasureComponent& treasure) {
	String title;
	const char* options[2] = { "Yes", "No" };

	title = createMenuTitle(inventory, &*treasure.getItem());
	Menu m(title.c_str(), options, 2, GameView::getInstance());

	if (!m.select()) {
		GameView::getInstance()->print("Item getted");
		GameView::getInstance()->print();
		Item* swap = treasure.getItem();
		inventory.swapItem(swap);
		treasure.setItem(swap);
	}
	treasure.entity->setIsActive(false);
}
