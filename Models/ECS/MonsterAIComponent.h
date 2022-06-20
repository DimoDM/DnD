#pragma once
#include"ECS.h"
#include"TransformComponent.h"
#include"../../Structures/Collection.h"
#include"../../Structures/Vector2D.h"
#include<math.h>
#include"../../Service/GetDistance.h"
#include"../../Service/RandomValues.h"
#include"../../Views/GameView.h"

using namespace std;

/// <summary>
/// control entityies that attack player
/// </summary>
class MonsterAIComponent : public Component
{
	bool isVisible = true;
	Collection<Entity>* players;
	TransformComponent* transform = nullptr;
	const int MAXDISTANCE = GameView::getInstance()->getMaxWidth() * 3;
	/// <summary>
	/// Target the closest player to attack
	/// </summary>
	/// <returns></returns>
	const int getIndexOfTheClosestPlayer() const;
	/// <summary>
	/// ...initialize velocity of wich monster will move 
	/// </summary>
	/// <param name="monsterPos"></param>
	/// <param name="playerPos"></param>
	/// <param name="distance"></param>
	/// <returns></returns>
	const Vector2D newVel(const Vector2D& monsterPos, const Vector2D& playerPos, int distance) const;


public:
	
	MonsterAIComponent();

	MonsterAIComponent(Collection<Entity>& ps);
	/// <summary>
	/// ...initialize transform component with random coordinates if there is no such
	/// </summary>
	void init() override;
	/// <summary>
	/// ...move monster
	/// </summary>
	void update() override;

};