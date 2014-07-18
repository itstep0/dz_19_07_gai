/* 
 * File:   crime.h
 * Author: hawk
 *
 * Created on 17 Июль 2014 г., 16:42
 */

#ifndef CRIME_H
#define	CRIME_H

#include <string>
#include <iostream>

using namespace std;

class CrimeList
{
public:
	CrimeList();
	~CrimeList();
	
	void addCrime(string crimeDescr);
	void printAllCrimes() const;
	
private:
	struct crime
	{
		crime* _next;
		unsigned long long _dateTime;
		string _descr;
		
	};

	crime* _firstCrime;
	crime* _lastCrime;
	int _crimeCount;
};


#endif	/* CRIME_H */

