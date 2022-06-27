#pragma once
#include"../Structures/Vector.h"
#include"ConsoleViewer.h"

class GameView : public ConsoleViewer
{
	const int MAXWIDTH = 100;
	const int MAXHEIGHT = 100;
	int width = 10;
	int height = 10;
	/// <summary>
	/// array for game graphics
	/// </summary>
	Vector<Vector<char>> gameTextures;

	static GameView* instance;

	/// <summary>
	/// create instance with default parameters
	/// </summary>
	GameView();
	/// <summary>
	/// create instance with custom parameters
	/// </summary>
	/// <param name="width"></param>
	/// <param name="height"></param>
	GameView(int width, int height);

public:

	/// <summary>
	/// get instance of game view
	/// </summary>
	/// <returns></returns>
	static GameView* getInstance();
	/// <summary>
	/// create game view with specific width and height
	/// </summary>
	/// <param name="width"></param>
	/// <param name="height"></param>
	/// <returns></returns>
	static GameView* createInstance(int width, int height);


	/// <summary>
	/// print game graphics
	/// </summary>
	void printGameTextures();
	/// <summary>
	/// initialize array for game graphics
	/// </summary>
	/// <param name="widht"></param>
	/// <param name="height"></param>
	void initMap(int widht, int height);

	/// <summary>
	/// declare one element from game array(playing window)
	/// </summary>
	/// <param name="texture"></param>
	/// <param name="xPos"></param>
	/// <param name="yPos"></param>
	void loadGameTexture(const char texture, int xPos, int yPos);
	/// <summary>
	/// get element from map
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <returns></returns>
	const char getElementFromGameMap(int x, int y) const;
	const int getMaxWidth() const;
	const int getMaxHeight() const;
	const int getWidth() const;
	const int getHeight() const;

	/// <summary>
	/// print everything from text var
	/// </summary>
	void print() override;
	/// <summary>
	/// print specific text on the console
	/// </summary>
	/// <param name="text"></param>
	void print(const char* text) override;
	/// <summary>
	/// print specific text and go to next line
	/// </summary>
	/// <param name="text"></param>
	void println(const char* text) override;

	void free();
};