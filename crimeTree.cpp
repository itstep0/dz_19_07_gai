#include "crimeTree.h"

using namespace std;

CrimeTree::CrimeTree(): _nodesCount(0), _root(nullptr)
{
}

CrimeTree::~CrimeTree()
{
	if (this->_root != nullptr)
	{
		delNodes(this->_root);
		delete this->_root;
	}
}

void CrimeTree::addCrime()
{
	unsigned int num;
	string crimeDescr;

	cout << "Enter number of auto:" << endl;
	cin >> num;
	cin.ignore();
	
	cout << "Enter crime description:" << endl;
	getline(cin, crimeDescr);
	cin.ignore();
	
	this->add(this->_root, num, crimeDescr);
}

void CrimeTree::printAll()
{
	this->printAllNodes(this->_root);
}

void CrimeTree::printByNumber()
{
	unsigned int num;
	cout << "Enter number:" << endl;
	cin >> num;
	
	this->printByNum(this->_root, num);
}

void CrimeTree::printAllInRange()
{
	unsigned int f,l;
	cout << "Enter first number of range:" << endl;
	cin >> f;
	cin.ignore();

	cout << "Enter last number of range:" << endl;
	cin >> l;
	cin.ignore();


	this->printByNumRange(this->_root, f, l);
}

void CrimeTree::clearDatabase()
{
	this->delNodes(this->_root);
}

/*****************************************************************************/

void CrimeTree::add(Node*& node, unsigned int num, string crimeDescr)
{
	if (node == nullptr)
	{
		node = new Node();
		node->_number = num;
		node->_crimes = new CrimeList();
		node->_crimes->addCrime(crimeDescr);
		node->_lPtr = nullptr;
		node->_rPtr = nullptr;
	} else if (num > node->_number)
	{
		add(node->_rPtr, num, crimeDescr);
	} else if (num < node->_number)
	{
		add(node->_lPtr, num, crimeDescr);
	} else if (node->_number == num)
	{
		node->_crimes->addCrime(crimeDescr);
	} else 
	{
		cout << "Something wrong... Think about" << endl;
	}
	
}

void CrimeTree::printAllNodes(const Node* node) const
{
	if (node->_lPtr != nullptr)
	{
		printAllNodes(node->_lPtr);
	} else if (node->_rPtr != nullptr)
	{
		printAllNodes(node->_rPtr);
	}
	
	cout << this->_delim << endl;
	cout << node->_number << endl;
	node->_crimes->printAllCrimes();
	cout << this->_delim << endl;

}

void CrimeTree::printByNum(const Node* node, const unsigned int num) const
{
	if (num > node->_number)
	{
		printByNum(node->_rPtr, num);
	}
	else if (num < node->_number)
	{
		printByNum(node->_lPtr, num);
	}
	else if (num == node->_number)
	{
		node->_crimes->printAllCrimes();
	}
	else 
	{
		cout << "Number not found!" << endl;
	}
}

void CrimeTree::printByNumRange(const Node* node, const unsigned int first, const unsigned int last) const
{
	if (node->_number >= first && node->_number <= last)
	{
		cout << this->_delim << endl;
		cout << "Number " << node->_number << ":" << endl;
		node->_crimes->printAllCrimes();
		cout << this->_delim << endl << endl;
	}
	if (node->_lPtr != nullptr)
	{
		printByNumRange(node->_lPtr, first, last);
	}
	if (node->_rPtr != nullptr)
	{
		printByNumRange(node->_rPtr, first, last);
	}

}

void CrimeTree::delNodes(Node*& node)
{
	if (node->_lPtr == nullptr && node->_rPtr == nullptr)
	{
		delete node->_crimes;
		delete node;
	}
	else if (node->_lPtr != nullptr)
	{
		delNodes(node->_lPtr);
	}
	else if (node->_rPtr != nullptr)
	{
		delNodes(node->_rPtr);
	}
	else 
	{
		cout << "Maybe something wrong..." << endl;
	}
}
