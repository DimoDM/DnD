#include "TextureManager.h"
#include "ConsoleViewer.h"

void TextureManager::LoadTexture(const char texture, int xPos, int yPos)
{
	ConsoleViewer::getInstance()->loadGameTexture(texture, xPos, yPos);
}
