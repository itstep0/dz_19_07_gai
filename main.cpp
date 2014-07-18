/* 
 * File:   main.cpp
 * Author: hawk
 *
 * Created on 17 Июль 2014 г., 16:32
 */

#include <iostream>
#include <string>
#include "menu.h"
#ifndef CRIMETREE_H
#include "crimeTree.h"
#endif
using namespace std;

Menu* createMenu()
{
	Menu* menu = new Menu();
	menu->addItem("Add new crime", &CrimeTree::addCrime);
	menu->addItem("Print all database", &CrimeTree::printAll);
	menu->addItem("Print crimes by number:", &CrimeTree::printByNumber);
	menu->addItem("Print crimes in range:", &CrimeTree::printAllInRange);
	menu->addItem("Clear database:", &CrimeTree::clearDatabase);
	
	return menu;
}

int main()
{
	int ch;
	Menu* myMenu = createMenu();
	myMenu->printMenu();
	ch = myMenu->getUserChoise();

	CrimeTree* crimesDB = new CrimeTree();
	
	
	while (ch != -1)
	{
		if (ch > 0 && ch <= myMenu->getItemsCount())
		{
			(crimesDB->*myMenu->getAction(ch - 1))();
		}
		myMenu->printMenu();
		ch = myMenu->getUserChoise();
	}
	
	
	
	return 0;
}
