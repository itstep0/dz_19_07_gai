#include "menu.h"
using namespace std;

Menu::Menu(): _itemsCount(0)
{
}


void Menu::addItem(string itemText, mPtr func)
{
	MenuItem tmp;
	tmp._itemText = itemText;
	tmp._methodPtr = func;
	
	this->_items.push_back(tmp);
	++this->_itemsCount;
}

void Menu::printMenu() const
{
	int counter = 1;
	for (auto it = this->_items.begin(); it != this->_items.end(); ++it)
	{
		cout << counter << ". " << (*it)._itemText << endl;
		++counter;
	}
}

int Menu::getUserChoise()
{
	int ch;
	cout << endl << endl << "Enter choice( for exit enter -1): " << endl;
	cin >> ch;
	return ch;
}

const int Menu::getItemsCount() const
{
	return this->_itemsCount;
}


mPtr Menu::getAction(int ch)
{
	return this->_items.at(ch)._methodPtr;
}

