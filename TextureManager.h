#pragma once

class TextureManager
{
public:
	static void LoadTexture(const char texture);
	static void Draw(const char* tex, int xPos, int yPos);
};
