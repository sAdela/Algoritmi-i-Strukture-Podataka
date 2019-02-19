#pragma once

#include <string>
using namespace std;

template <class Tip>
class Lista 
{
public:
	virtual void Dodaj(Tip x) = 0;

	virtual Tip ukloni() = 0;

	virtual bool isPrazan() = 0;

	virtual Tip& operator[](int i) = 0;

	virtual void Print() = 0;

	virtual int count() = 0;

	virtual bool sadrzi(Tip v) = 0;

};


