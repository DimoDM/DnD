#pragma once
#include"ECS.h"

/// <summary>
/// ...This component is responcible to storage textures of game graphics and their's coordinates and draw them
/// </summary>
class TileComponent : public Component
{
	int x = 0;
	int y = 0;
	char texture = ' ';
	bool visible = true;
public:

	TileComponent();
	TileComponent(int x, int y, const char tex);

	/// <summary>
	/// ...initialize game texture in viewer
	/// </summary>
	void init() override;
	/// <summary>
	/// ...save game texture
	/// </summary>
	void draw() override;

	/// <summary>
	/// ...unused feature, do nothing at the moment
	/// </summary>
	void makeVisible();

	const int getX() const;
	const int getY() const;
};