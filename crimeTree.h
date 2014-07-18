/* 
 * File:   crimeTree.h
 * Author: hawk
 *
 * Created on 17 Июль 2014 г., 17:28
 */

#ifndef CRIMETREE_H
#define	CRIMETREE_H

#include <iostream>
#include <fstream>
#include <string>
#include "crime.h"

using namespace std;

struct Node
{
	unsigned int _number;
	CrimeList* _crimes;
	
	Node* _lPtr;
	Node* _rPtr;
	
	Node():_crimes(nullptr)
	{
		
	}
	
	Node(unsigned int num):_number(num), _lPtr(nullptr), _rPtr(nullptr), _crimes(nullptr)
	{
		
	}

	~Node()
	{
		if (this->_crimes != nullptr)
			delete this->_crimes;
	}
	
	bool operator< (const Node& oth)
	{
		return this->_number < oth._number;
	}

	bool operator> (const Node& oth);

	
};



class CrimeTree
{
public:
	CrimeTree();
	~CrimeTree();
	
	void addCrime();
	void printAll();
	void printByNumber();
	void printAllInRange();
	void clearDatabase();
private:
	Node* _root;
	unsigned int _nodesCount;
	const string _delim = "*****************************************************";
	
	void add(Node*& node, unsigned int num, string crimeDescr);
	void printAllNodes(const Node* node) const;
	void printByNum(const Node* node, const unsigned int num) const;
	void printByNumRange(const Node* node, const unsigned int first, const unsigned int last) const;
	void delNodes(Node*& nPtr);
	
};


#endif	/* CRIMETREE_H */

