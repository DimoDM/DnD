#pragma once
#include"ECS.h"
#include"../GameView.h"
#include"../Structures/String.h"
#include"../Menu.h"

class StatsComponent : public Component
{

	int health = 50;
	int mana = 20;
	int strenght = 30;
	int level = 1;
	int xp = 0;
	int levelCompleted = 1;

	void levelUp() {
		switch (level) {
		case 1: if (xp >= 2) { xp -= 2; level++; increaceLevel(30); levelUp(); }; break;
		case 2: if (xp >= 6) { xp -= 6; level++; increaceLevel(30); levelUp(); }; break;
		case 3: if (xp >= 15) { xp -= 15; level++; increaceLevel(30); levelUp(); }; break;
		case 4: if (xp >= 32) { xp -= 32; level++; increaceLevel(30); levelUp(); }; break;
		default: if (xp >= 70) { xp -= 70; level++; increaceLevel(30); levelUp(); }; break;
		}
	}

	void increaceLevel(int points) {
		const char* statsOptions[3] = { "Health", "Mana", "Strenght" };
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

public:

	StatsComponent() : Component() {
		type = 8;
	}

	StatsComponent(int h, int m, int s, int l, int x, int c) : Component() {
		type = 8;
		health = h;
		mana = m;
		level = l;
		strenght = s;
		xp = x;
		levelCompleted = c;
	}

	void init() override {}

	void update() override {
	}

	void draw() override {
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

	const int getStrenght() const {
		return strenght;
	}

	const int getMana() const {
		return mana;
	}

	const int getHealth() const {
		return health;
	}

	const int getLevel() const {
		return level;
	}

	const int getCompletedLevel() const {
		return levelCompleted;
	}

	void completeLevel() {
		levelCompleted++;
	}

	const int getXp() const {
		return xp;
	}

	void addXp(int value) {
		xp += value;
		levelUp();
	}

	void reduceMana(int value) {
		mana -= value;
	}

	void addHealth(int value) {
		health += value;
	}

	void takeDamage(int value) {
		int protection = entity->getComponent<InventoryComponent>().getArmorDef();
		health -= value - protection;
		if (health <= 0) {
			entity->getComponent<TransformComponent>().setPos(0, 0);
			entity->setIsActive(false);
		}
	}
};