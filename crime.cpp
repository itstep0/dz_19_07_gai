#include "crime.h"
#include <ctime>


CrimeList::CrimeList(): _crimeCount(0), _firstCrime(nullptr), _lastCrime(nullptr)
{
	
}

CrimeList::~CrimeList()
{
	crime* tmpCrime = this->_firstCrime;
	crime* tmp;
	while (tmpCrime->_next != this->_lastCrime)
	{
		tmp = tmpCrime->_next;
		delete tmpCrime;
		tmpCrime = tmp;
	}
	this->_firstCrime = nullptr;
	delete this->_lastCrime;
}

void CrimeList::addCrime(string crimeDescr)
{
	crime* newCrime = new crime;
	newCrime->_dateTime = time(NULL);
	newCrime->_descr = crimeDescr;
	newCrime->_next = nullptr;
	if (this->_firstCrime == nullptr)
	{
		this->_firstCrime = newCrime;
	} else 
	{
		this->_lastCrime->_next = newCrime;
	}

	this->_lastCrime = newCrime;
	++this->_crimeCount;
	
}

void CrimeList::printAllCrimes() const
{
	if (this->_firstCrime != nullptr)
	{
		crime* curr = this->_firstCrime;
		for (int i =0; i < this->_crimeCount; ++i)
		{
			cout << curr->_dateTime << "\t" << curr->_descr << endl;
			curr = curr->_next;
		}
	}
}


