#pragma once

#include "Cvor.h"

template <class Tip>
class PrioritetniRed{

public:

	virtual void Dodaj(Tip x) = 0;

	virtual Tip ukloni() = 0;

	virtual bool JeLiPrazan() = 0;

	virtual void Print()=0;
};

