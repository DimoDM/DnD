#include"GameView.h"
#include<iostream>
using namespace std;

GameView* GameView::instance = nullptr;

GameView::GameView() : ConsoleViewer() {
	initMap(width, height);
}

GameView::GameView(int width, int height) : ConsoleViewer() {
	this->width = width;
	this->height = height;
	initMap(width, height);
}

void GameView::initMap(int widht, int height)
{
	if (width > MAXWIDTH || width < 3 || height > MAXHEIGHT || height < 3) throw new exception("invalid arguments");
	for (int i = 0; i < height; i++) {
		gameTextures.push_back(Vector<char>());
		for (int j = 0; j < width; j++) {
			gameTextures[i].push_back(' ');
		}
	}
}

void GameView::loadGameTexture(const char texture, int xPos, int yPos)
{
	if (xPos > width || yPos > height) throw new std::exception("invalid cell");
	gameTextures[yPos][xPos] = texture;
}

const char GameView::getElementFromGameMap(int x, int y) const
{
	if (x > width || y > height) throw new std::exception("invalid cell");
	return gameTextures.getArray()[y][x];
}

const int GameView::getMaxWidth() const
{
	return MAXWIDTH;
}

const int GameView::getMaxHeight() const
{
	return MAXHEIGHT;
}

const int GameView::getWidth() const
{
	return width;
}

const int GameView::getHeight() const
{
	return height;
}

void GameView::print()
{
	system("CLS");
	printGameTextures();
	ConsoleViewer::print();
}

void GameView::print(const char* text)
{
	ConsoleViewer::print(text);
}

void GameView::println(const char* text)
{
	ConsoleViewer::println(text);
}

void GameView::printGameTextures()
{
	for (int i = 0; i < gameTextures.getSize(); i++) {
		cout << "|";
		for (int j = 0; j < gameTextures[i].getSize(); j++) {
			cout << gameTextures[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < width; i++) cout << "-";
	cout << endl;
}

GameView* GameView::getInstance()
{
	if (instance == nullptr) instance = new GameView();
	return instance;
}

GameView* GameView::createInstance(int width, int height)
{
	if (instance == nullptr) instance = new GameView(width, height);
	return instance;
}