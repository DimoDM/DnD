#pragma once
#include"ConsoleViewer.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Random
{
public:
	static int getRandomNum(int start, int end) {
		int random;
		srand(time(NULL));
		random = rand() % end + start;
		return random;
	}

	static Vector2D generateRandomCoordinates() {
		return { getRandomNum(1, ConsoleViewer::getInstance()->getMaxWidth() - 1), getRandomNum(1, ConsoleViewer::getInstance()->getMaxHeight() - 1) };
	}

	static Vector2D generateValidCoordinates() {
		Vector2D c = generateRandomCoordinates();
		while (ConsoleViewer::getInstance()->getElementFromGameMap(c.x, c.y) != '.') {
			c = generateRandomCoordinates();
		}
		return c;
	}

};
