#pragma once
#include"Structures/Vector.h"
#include"Structures/String.h"
#include<iostream>

class ConsoleViewer
{
	int width = 16;
	int height = 16;
	String text = "";
	Vector<Vector<char>> gameTextures; // array for game graphics
	void printGameTextures(); // print game graphics
	void initMap(int widht, int height); // initialize array for game graphics
	ConsoleViewer(); // create instance with default parameters
	ConsoleViewer(int width, int height);  // create instance with custom parameters

	static ConsoleViewer* instance; // I want this to be same everywhere so I will use Singleton pattern

public:

	static ConsoleViewer* getInstance();
	static ConsoleViewer* createInstance(int width, int height);
	
	void print(); // print everything
	void loadGameTexture(const char texture, int xPos, int yPos);
	const char getElementFromGameMap(int x, int y) const;
	const int getMaxWidth() const;
	const int getMaxHeight() const;
	void print(const char* text);
	void println(const char* text);
};