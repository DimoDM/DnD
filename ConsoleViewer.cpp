#include"ConsoleViewer.h"
#include<iostream>
using namespace std;

ConsoleViewer* ConsoleViewer::instance = nullptr;

void ConsoleViewer::printGameTextures()
{
	for (int i = 0; i < gameTextures.getSize(); i++) {
		cout << "|";
		for (int j = 0; j < gameTextures[i].getSize(); j++) {
			cout << gameTextures[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < width; i++) cout << " -";
	cout << endl;
}

void ConsoleViewer::initMap(int widht, int height)
{
	for (int i = 0; i < height; i++) {
		gameTextures.push_back(Vector<char>());
		for (int j = 0; j < width; j++) {
			gameTextures[i].push_back('+');
		}
	}
}

ConsoleViewer::ConsoleViewer()
{
	initMap(width, height);
}

ConsoleViewer::ConsoleViewer(int width, int height) : width(width), height(height)
{
	initMap(width, height);
}

ConsoleViewer* ConsoleViewer::getInstance()
{	
	if (instance == nullptr) instance = new ConsoleViewer();
	return instance;
}

ConsoleViewer* ConsoleViewer::createInstance(int width, int height)
{
	if (instance == nullptr) instance = new ConsoleViewer(width, height);
	return instance;
}

void ConsoleViewer::print()
{
	printGameTextures();
}
