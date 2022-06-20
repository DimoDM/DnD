#pragma once
#include"../Structures/Vector.h"
#include"../Structures/String.h"

/// <summary>
/// handle and print text to the console
/// </summary>
class ConsoleViewer
{
private:

	String text = "";
	/// <summary>
	/// I want this to be same everywhere so I will try to use Singleton pattern
	/// </summary>
	static ConsoleViewer* instance;

protected:

	/// <summary>
	/// create instance with default parameters
	/// </summary>
	ConsoleViewer() {
		system("mode con COLS=700");
		system("Title = DnD");
	}

public:

	static ConsoleViewer* getInstance();
	
	/// <summary>
	/// ...print everything
	/// </summary>
	virtual void print();
	/// <summary>
	/// ...print specific text
	/// </summary>
	/// <param name="text"></param>
	virtual void print(const char* text);
	/// <summary>
	/// ...print specific text and go to next line
	/// </summary>
	/// <param name="text"></param>
	virtual void println(const char* text);
};