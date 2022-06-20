#pragma once
#include"./../Views/GameView.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include"../Structures/Vector2D.h"

//TODO change header name
class Random
{
public:
	/// <summary>
	/// generate random number in range from start to end
	/// </summary>
	/// <param name="start"></param>
	/// <param name="end"></param>
	/// <returns></returns>
	static int getRandomNum(int start, int end);

	/// <summary>
	/// generete 2d vector
	/// </summary>
	/// <returns></returns>
	static Vector2D generateRandomCoordinates();

	/// <summary>
	/// generete coordinates that are free
	/// </summary>
	/// <returns></returns>
	static Vector2D generateValidCoordinates();

};
