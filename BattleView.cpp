#include"BattleView.h"

BattleView* BattleView::instance = nullptr;

BattleView::BattleView() : ConsoleViewer() {
}

void BattleView::print()
{
	ConsoleViewer::print();
}

void BattleView::print(const char* text)
{
	system("CLS");
	ConsoleViewer::print(text);
}

void BattleView::println(const char* text)
{
	ConsoleViewer::println(text);
}

BattleView* BattleView::getInstance()
{
	if (instance == nullptr) instance = new BattleView();
	return instance;
}
