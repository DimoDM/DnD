#pragma once
#include"ECS.h"

/// <summary>
/// handle stats of entity
/// </summary>
class StatsComponent : public Component
{

	int health = 50;
	int mana = 20;
	int strenght = 30;
	int level = 1;
	int xp = 0;
	int levelCompleted = 1;

	/// <summary>
	/// level up logic
	/// </summary>
	void levelUp();

	/// <summary>
	/// level up logic
	/// </summary>
	/// <param name="points"></param>
	void increaseLevel(int points);

public:

	StatsComponent();

	StatsComponent(int h, int m, int s, int l, int x, int c);

	/// <summary>
	/// ...show entity stats
	/// </summary>
	void draw();

	const int getStrenght() const;

	const int getMana() const;

	const int getHealth() const;

	const int getLevel() const;

	const int getCompletedLevel() const;

	void completeLevel();

	const int getXp() const;

	void addXp(int value);

	void reduceMana(int value);

	void addHealth(int value);

	/// <summary>
	/// ...reduce health and if hit zero make entity non active
	/// </summary>
	/// <param name="value"></param>
	void takeDamage(int value);
};