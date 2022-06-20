#include"../TileComponent.h"
#include"../../../Service/TextureManager.h"

TileComponent::TileComponent() : Component() {
	type = 1;
}

TileComponent::TileComponent(int x, int y, const char tex) : Component() {
	type = 1;
	this->x = x;
	this->y = y;
	this->texture = tex;
}

/// <summary>
/// ...initialize game texture in viewer
/// </summary>
void TileComponent::init() {
	if (visible) TextureManager::LoadTexture(texture, x, y);
}

/// <summary>
/// ...save game texture
/// </summary>
void TileComponent::draw() {
	if (visible) TextureManager::LoadTexture(texture, x, y);
}

/// <summary>
/// ...unused feature
/// </summary>
void TileComponent::makeVisible() {
	visible = true;
	TextureManager::LoadTexture(texture, x, y);
}

const int TileComponent::getX() const {
	return x;
}

const int TileComponent::getY() const {
	return y;
}