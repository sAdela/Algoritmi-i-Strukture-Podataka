#pragma once
#include "Hesiranje.h"
#include "ListaPov.h"

template <class Tip>
class HeshiranjeUlancavanje:public Hesiranje<Tip>
{
	ListaPov<Tip>* Niz;
	int max_size;
	int IzracunajHash(Tip k)
	{
		return k % max_size;
	}
public:
	HeshiranjeUlancavanjem(int max_size=10)
	{
		this->max_size = max_size;
		Niz = new ListaPov<Tip>[10];
	}
	void dodaj(Tip k)
	{
		int p = IzracunajHash(k);
		ListaPov<Tip>& lista = Niz[p];
		lista.dodaj(k);
	}
	bool ukloni(Tip k)
	{
		cout << "Uklonjeno: " << k << endl;
		int p = IzracunajHash(k);
		ListaPov<Tip>& lista = Niz[p];
		return lista.ukloni(k);
	}
	void print()
	{
		for (int i=0;i<max_size;i++){
			Niz[i].print();
		}
	}
};
