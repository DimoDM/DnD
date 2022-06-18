#pragma once
#include"ECS.h"
#include"../GameView.h"
#include"../Structures/String.h"
#include"../Game.h"

class StatsComponent : public Component
{

	int health = 50;
	int mana = 20;
	int strenght = 30;

public:

	StatsComponent() : Component() {
		type = 8;
	}

	StatsComponent(int h, int m, int s) : Component() {
		type = 8;
		health = h;
		mana = m;
		strenght = s;
	}

	void init() override {}

	void update() override {}

	void draw() override {
		if (entity->hasGroup(Game::groupPlayer)) {
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

	void reduceMana(int value) {
		mana -= value;
	}

	void takeDamage(int value) {
		health -= value;
	}
};