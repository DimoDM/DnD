#pragma once
#include"ConsoleViewer.h"

class BattleView : public ConsoleViewer
{

	static BattleView* instance;

	BattleView(); // create instance with default parameters
	BattleView(int width, int height);  // create instance with custom parameters

public:

	static BattleView* getInstance();

	void print() override; // print everything
	void print(const char* text) override; // print specific text
	void println(const char* text) override; // print specific text and go to next line
};