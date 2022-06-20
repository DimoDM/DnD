#pragma once
#include"ECS.h"
#include"../TextureManager.h"

class TileComponent : public Component
{
	int x = 0;
	int y = 0;
	char texture = ' ';
	bool visible = true;
public:

	TileComponent() : Component() {
		type = 0;
	}

	TileComponent(int x, int y, const char tex) : Component() {
		type = 0;
		this->x = x;
		this->y = y;
		this->texture = tex;
	}

	void init() override {
		if(visible) TextureManager::LoadTexture(texture, x, y);
	}

	void update() override {
	}
	void draw() override {
		if (visible) TextureManager::LoadTexture(texture, x, y);
	}

	void makeVisible() {
		visible = true;
		TextureManager::LoadTexture(texture, x, y);
	}

	const int getX() const {
		return x;
	}

	const int getY() const {
		return y;
	}
};