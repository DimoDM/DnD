#pragma once
#include"ConsoleViewer.h"

/// <summary>
/// this class is used to print all events during battle phase
/// </summary>
class BattleView : public ConsoleViewer
{

	static BattleView* instance;

	/// <summary>
	/// ...create instance with default parameters
	/// </summary>
	BattleView();
	/// <summary>
	/// ...create instance with custom parameters
	/// </summary>
	/// <param name="width"></param>
	/// <param name="height"></param>
	BattleView(int width, int height);

public:

	static BattleView* getInstance();

	/// <summary>
	/// ...print everything
	/// </summary>
	void print() override;
	/// <summary>
	/// ...print specific text
	/// </summary>
	/// <param name="text"></param>
	void print(const char* text) override;
	/// <summary>
	/// ...print specific text and go to next line
	/// </summary>
	/// <param name="text"></param>
	void println(const char* text) override;

	void free();
};