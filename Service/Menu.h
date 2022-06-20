#pragma once
#include"../Structures/String.h"
#include"../Structures/Vector.h"
#include"../Views/ConsoleViewer.h"
#include<conio.h>

class Menu
{
	String title;
	Vector<String> options;
	ConsoleViewer* viewer;

	/// <summary>
	/// move cursor upwards
	/// </summary>
	/// <param name="start"></param>
	void substractOne(int& start) const;
	/// <summary>
	/// move cursor downwards
	/// </summary>
	/// <param name="start"></param>
	void addOne(int& start) const;

	/// <summary>
	/// print menu
	/// </summary>
	/// <param name="state"></param>
	void printMenu(int state) const;

	/// <summary>
	/// select option from menu and return maded choice
	/// </summary>
	/// <param name="start"></param>
	/// <returns></returns>
	const int select(int start) const;

public:

	Menu(const char* title, const char** options, int numOfOptions, ConsoleViewer* viewer);

	Menu(const char* title, Vector<String> options, ConsoleViewer* viewer);

	/// <summary>
	/// select option from menu starting from begginign of the list
	/// </summary>
	/// <returns></returns>
	const int select() const;

};