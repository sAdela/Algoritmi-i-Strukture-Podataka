#pragma once
#include <iostream>
using namespace std;

template <class Tip>
class Cvor
{
	Cvor* next;
	Tip info;
public:
	Cvor(Tip info, Cvor<Tip>* next) : info(info)
	{
		this->next = next;
	}
};
