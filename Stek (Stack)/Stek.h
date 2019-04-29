#pragma once

#include "Cvor.h"

template <class Tip>
class Stek {
	
public:

	virtual void dodaj(Tip x) = 0;

	virtual Tip ukloni() = 0;
	
	virtual Tip vrh() = 0;

	virtual bool JeLiPrazan() = 0;

	virtual void print() = 0;
	
	virtual bool sadrzi(Tip x) = 0;
};
