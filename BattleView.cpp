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

BattleView* BattleView::createInstance(int width, int height)
{
	if (instance == nullptr) instance = new BattleView(width, height);
	return instance;
}