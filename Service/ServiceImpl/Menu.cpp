#include"../Menu.h"

void Menu::substractOne(int& start) const {
	start = start - 1 < 0 ? options.getSize() - 1 : start - 1;
}

void Menu::addOne(int& start) const {
	start = start + 1 < options.getSize() ? start + 1 : 0;
}


void Menu::printMenu(int state) const {
	viewer->println(title.c_str());
	for (int i = 0; i < options.getSize(); i++) {
		viewer->print(i == state ? "> " : "  ");
		viewer->println(options.getArray()[i].c_str());
	}
	system("CLS");
	viewer->print();
}

const int Menu::select(int start) const {
	printMenu(start);
	char input = _getch();
	switch (input)
	{
	case 'W':
	case 'w':
	case 72:
		substractOne(start); return select(start);
	case 'S':
	case 's':
	case 80:
		addOne(start); return select(start);
	case 13: return start;
	default: return select(start);
	}
}

Menu::Menu(const char* title, const char** options, int numOfOptions, ConsoleViewer* viewer) {
	this->title = title;
	this->viewer = viewer;
	for (int i = 0; i < numOfOptions; i++) {
		this->options.push_back(options[i]);
	}
}

Menu::Menu(const char* title, Vector<String> options, ConsoleViewer* viewer) {
	this->title = title;
	this->options = options;
	this->viewer = viewer;
}

const int Menu::select() const {
	return select(0);
}