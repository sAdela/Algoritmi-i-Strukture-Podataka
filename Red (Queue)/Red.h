#pragma once

#include "Cvor.h"

template <class Tip>
class Red {

public:

	virtual void Dodaj(Tip x) = 0;
	
	virtual Tip ukloni() = 0;

	virtual bool JeLiPrazan() = 0;
  
  virtual bool sadrzi(Tip x) = 0;
  
	virtual void print() = 0;

};
