#include<iostream>
#include"Game.h"
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include"Engine.h"

int main()
{
	Engine e;
		e.run();
	//system("mode 650");
	//SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	//SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	system("Title = DnD");
	Game game;
	game.init();
	while (true) {
		system("CLS");
		game.draw();
		game.update();
	}
	std::cout << "she-wolf";
	return 0;
}
