#pragma once
#include"ECS.h"
#include"../ConsoleViewer.h"
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
			ConsoleViewer::getInstance()->println("Stats: ");
			ConsoleViewer::getInstance()->println(h.c_str());
			ConsoleViewer::getInstance()->println(m.c_str());
			ConsoleViewer::getInstance()->println(s.c_str());
		}
	}
};