#include"../ConsoleViewer.h"
#include<iostream>
using namespace std;

ConsoleViewer* ConsoleViewer::instance = nullptr;

ConsoleViewer* ConsoleViewer::getInstance()
{	
	if (instance == nullptr) instance = new ConsoleViewer();
	return instance;
}

void ConsoleViewer::print()
{
	cout << text.c_str();
	text = "";
}

void ConsoleViewer::print(const char* text)
{
	this->text.concat(text);
}

void ConsoleViewer::println(const char* text)
{
	this->text.concat(text);
	this->text.concat("\n");
}

void ConsoleViewer::free()
{
	delete instance;
}
