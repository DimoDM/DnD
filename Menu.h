#pragma once
#include"Structures/String.h"
#include"Structures/Vector.h"
#include"ConsoleViewer.h"
#include<conio.h>

class Menu
{
	String title;
	Vector<String> options;
	ConsoleViewer* viewer;

	void substractOne(int& start) {
		start = start - 1 < 0 ? options.getSize() - 1 : start - 1;
	}
	void addOne(int& start) {
		start = start + 1 < options.getSize() ? start + 1 : 0;
	}

	void printMenu(int state) {
		for (int i = 0; i < options.getSize(); i++) {
			viewer->print(i == state ? "> " : "  ");
			viewer->println(options[i].c_str());
		}
	}

	int select(int start) {
		printMenu(start);
		char input = _getch();
		switch (input)
		{
		case 'W': substractOne(start); return select(start);
		case 'S': addOne(start); return select(start);
		case 13: return start;
		default: break;
		}
	}

public:

	Menu(const char* title, const char** options, int numOfOptions, ConsoleViewer& viewer) {
		this->title = title;
		this->viewer = &viewer;
		for(int i = 0; i < numOfOptions; i++) {
			this->options.push_back(options[i]);
		}
	}

	Menu(const char* title, Vector<String> options) {
		this->title = title;
		this->options = options;
	}


	int select() {
		return select(0);
	}

};