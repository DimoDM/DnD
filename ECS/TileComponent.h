#pragma once
#include"ECS.h"
#include"../TextureManager.h"

class TileComponent : public Component
{
	int x;
	int y;
	char texture;
	bool visible = true;
public:

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
};