#pragma once
#include"ECS.h"
#include"../GameView.h"
#include"../Structures/String.h"

class StatsComponent : public Component
{

	int health = 50;
	int mana = 20;
	int strenght = 30;
	int level = 1;
	int xp = 0;

	void levelUp() {
		switch (level) {
		case 1: if (xp >= 2) { xp -= 2; level++; levelUp(); }; break;
		case 2: if (xp >= 6) { xp -= 6; level++; levelUp(); }; break;
		case 3: if (xp >= 15) { xp -= 15; level++; levelUp(); }; break;
		case 4: if (xp >= 32) { xp -= 32; level++; levelUp(); }; break;
		default: if (xp >= 70) { xp -= 70; level++; levelUp(); }; break;
		}
	}

public:

	StatsComponent() : Component() {
		type = 8;
	}

	StatsComponent(int h, int m, int s, int l, int x) : Component() {
		type = 8;
		health = h;
		mana = m;
		level = l;
		strenght = s;
		xp = x;
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
			GameView::getInstance()->println("Stats: ");
			GameView::getInstance()->println(h.c_str());
			GameView::getInstance()->println(m.c_str());
			GameView::getInstance()->println(s.c_str());
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

	void takeDamage(int value) {
		health -= value;
		if (health <= 0) {
			entity->getComponent<TransformComponent>().setPos(0, 0);
			entity->setIsActive(false);
		}
	}
};