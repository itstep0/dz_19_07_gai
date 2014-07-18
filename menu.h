/* 
 * File:   menu.h
 * Author: hawk
 *
 * Created on 18 Июль 2014 г., 11:30
 */

#ifndef MENU_H
#define	MENU_H

#include <string>
#include <vector>
#include "crimeTree.h"

using namespace std;

typedef void (CrimeTree::*mPtr)();

struct MenuItem
{
	string _itemText;
	mPtr _methodPtr;
};


class Menu
{
public:
	Menu();
	void addItem(string itemText, mPtr func);
	void printMenu() const;
	int getUserChoise();
	const int getItemsCount() const;
	mPtr getAction(int ch);
	
private:
vector<MenuItem> _items;
int _itemsCount;

};

#endif	/* MENU_H */

