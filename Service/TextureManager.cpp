#include "TextureManager.h"
#include "GameView.h"

void TextureManager::LoadTexture(const char texture, int xPos, int yPos)
{
	GameView::getInstance()->loadGameTexture(texture, xPos, yPos);
}
