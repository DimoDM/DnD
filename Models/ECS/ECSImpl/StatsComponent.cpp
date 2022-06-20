#include"../StatsComponent.h"
#include"../InventoryComponent.h"
#include"../TransformComponent.h"
#include"../../../Views/GameView.h"
#include"../../../Structures/String.h"
#include"../../../Service/Menu.h"
#include<iostream>
using namespace std;

StatsComponent::StatsComponent() : Component() {
	type = 8;
}

StatsComponent::StatsComponent(int h, int m, int s, int l, int x, int c) : Component() {
	type = 8;
	health = h;
	mana = m;
	level = l;
	strenght = s;
	xp = x;
	levelCompleted = c;
}

/// <summary>
/// ...show entity stats
/// </summary>
void StatsComponent::draw() {
	if (entity->hasGroup(0)) {
		String h("Health: ");
		h += health;
		String m("Mana: ");
		m += mana;
		String s("Strenght: ");
		s += strenght;
		String l("Level: ");
		l += level;
		GameView::getInstance()->println("Stats: ");
		GameView::getInstance()->println(h.c_str());
		GameView::getInstance()->println(m.c_str());
		GameView::getInstance()->println(s.c_str());
		GameView::getInstance()->println(l.c_str());
	}
}

/// <summary>
/// level up logic
/// </summary>
void StatsComponent::levelUp() {
	switch (level) {
	case 1: if (xp >= 2) { xp -= 2; level++; increaseLevel(30); levelUp(); }; break;
	case 2: if (xp >= 6) { xp -= 6; level++; increaseLevel(30); levelUp(); }; break;
	case 3: if (xp >= 15) { xp -= 15; level++; increaseLevel(30); levelUp(); }; break;
	case 4: if (xp >= 32) { xp -= 32; level++; increaseLevel(30); levelUp(); }; break;
	default: if (xp >= 70) { xp -= 70; level++; increaseLevel(30); levelUp(); }; break;
	}
}

/// <summary>
/// level up logic
/// </summary>
/// <param name="points"></param>
void StatsComponent::increaseLevel(int points) {
	const char* statsOptions[3] = { "Health", "Mana", "Strenght" };
	draw();
	Menu selectStat("Select Statuce to increace:", statsOptions, 3, GameView::getInstance());

	int p;
	while (points > 0) {
		int choice = selectStat.select();
		cout << "Available points: " << points << endl << "Enter points to increace with: ";
		cin >> p;
		p = points - p > 0 ? p : points;
		points -= p;
		switch (choice)
		{
		case 0: health += p; break;
		case 1: mana += p; break;
		case 2: strenght += p; break;
		default:
			break;
		}
	}
	ConsoleViewer::getInstance()->print();
}

/// <summary>
/// ...setters and getters
/// </summary>
/// <returns></returns>
const int StatsComponent::getStrenght() const {
	return strenght;
}

const int StatsComponent::getMana() const {
	return mana;
}

const int StatsComponent::getHealth() const {
	return health;
}

const int StatsComponent::getLevel() const {
	return level;
}

const int StatsComponent::getCompletedLevel() const {
	return levelCompleted;
}

void StatsComponent::completeLevel() {
	levelCompleted++;
}

const int StatsComponent::getXp() const {
	return xp;
}

void StatsComponent::addXp(int value) {
	xp += value;
	levelUp();
}

void StatsComponent::reduceMana(int value) {
	mana -= value;
}

void StatsComponent::addHealth(int value) {
	health += value;
}

/// <summary>
/// ...reduce health and if hit zero make entity non active
/// </summary>
/// <param name="value"></param>
void StatsComponent::takeDamage(int value) {
	int protection = entity->getComponent<InventoryComponent>().getArmorDef();
	health -= value - protection;
	if (health <= 0) {
		entity->getComponent<TransformComponent>().setPos(0, 0);
		entity->setIsActive(false);
	}
}