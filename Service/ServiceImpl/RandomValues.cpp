#include"../RandomValues.h"

/// <summary>
/// generate random number in range from start to end
/// </summary>
/// <param name="start"></param>
/// <param name="end"></param>
/// <returns></returns>
int Random::getRandomNum(int start, int end) {
	int random;
	srand(time(NULL));
	random = rand() % (end - start) + start;
	return random;
}

/// <summary>
/// generete 2d vector
/// </summary>
/// <returns></returns>
Vector2D Random::generateRandomCoordinates() {
	return { getRandomNum(2, GameView::getInstance()->getWidth() - 1), getRandomNum(2, GameView::getInstance()->getHeight() - 1) };
}

/// <summary>
/// generete coordinates that are free
/// </summary>
/// <returns></returns>
Vector2D Random::generateValidCoordinates() {
	Vector2D c = generateRandomCoordinates();
	while (GameView::getInstance()->getElementFromGameMap(c.x, c.y) != '.') {
		c = generateRandomCoordinates();
	}
	return c;
}