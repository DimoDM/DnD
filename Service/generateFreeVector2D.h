#pragma once
#include"GameView.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

//TODO change header name
class Random
{
public:
	static int getRandomNum(int start, int end) {
		int random;
		srand(time(NULL));
		random = rand() % (end - start) + start;
		return random;
	}

	static Vector2D generateRandomCoordinates() {
		return { getRandomNum(3, GameView::getInstance()->getWidth() - 3), getRandomNum(3, GameView::getInstance()->getHeight() - 3) };
	}

	static Vector2D generateValidCoordinates() {
		Vector2D c = generateRandomCoordinates();
		while (GameView::getInstance()->getElementFromGameMap(c.x, c.y) != '.') {
			c = generateRandomCoordinates();
		}
		return c;
	}

};
