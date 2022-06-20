#pragma once
#include"Structures/Vector.h"
#include"Structures/String.h"
#include<iostream>

class ConsoleViewer
{
private:

	String text = "";
	static ConsoleViewer* instance; // I want this to be same everywhere so I will use Singleton pattern

protected:

	ConsoleViewer() = default; // create instance with default parameters

public:

	static ConsoleViewer* getInstance();
	
	virtual void print(); // print everything
	virtual void print(const char* text); // print specific text
	virtual void println(const char* text); // print specific text and go to next line
};