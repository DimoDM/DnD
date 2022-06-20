#pragma once
#include"ECS.h"
#include"TileComponent.h"
#include"../../Service/RandomValues.h"
#include"../../Structures/Vector2D.h"
#include"../Items/ItemsList.h"

/// <summary>
/// handle storage of the treasure
/// </summary>
class TreasureComponent : public Component
{

	TileComponent* tile;
	Item* item = nullptr;
	Vector2D pos = {0, 0};
	int lvl;

public:

	TreasureComponent();
	TreasureComponent(int l);
	/// <summary>
	/// init TileComponent if one is not added and set random pos
	/// </summary>
	void init() override;

	Item* getItem() const;
	void setItem(const Item* i);
	void setItem(Weapon& weapon);
	void setItem(Armor& armor);
	void setItem(Spell& spell);
	void setItem();

	const Vector2D& getPos() const;

	~TreasureComponent();

};