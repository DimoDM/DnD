#pragma once
#include"Structures/Vector.h"
#include"ConsoleViewer.h"

class GameView : public ConsoleViewer
{
	const int MAXWIDTH = 100;
	const int MAXHEIGHT = 100;
	int width = 10;
	int height = 10;
	Vector<Vector<char>> gameTextures; // array for game graphics

	static GameView* instance;

	GameView(); // create instance with default parameters
	GameView(int width, int height);  // create instance with custom parameters

public:

	static GameView* getInstance();
	static GameView* createInstance(int width, int height);

	void printGameTextures(); // print game graphics
	void initMap(int widht, int height); // initialize array for game graphics

	void loadGameTexture(const char texture, int xPos, int yPos);
	const char getElementFromGameMap(int x, int y) const;
	const int getMaxWidth() const;
	const int getMaxHeight() const;

	void print() override; // print everything
	void print(const char* text) override; // print specific text
	void println(const char* text) override; // print specific text and go to next line
};