#pragma once
#include <iostream>
#include <exception>
#include "Hesiranje.h"

template <class Tip>
class HesiranjeOtvorenoAdresiranje :public Hesiranje<Tip>
{
	Tip* Niz;
	bool* Zauzeto;
  int max_size;
	int IzracunajHash(Tip k)
	{
		return k % max_size;
	}
	int brojac;
public:
	HeshiranjeOtvorenoAdresiranje(int n = 10){
		this->max_size = max_size;
		Niz = new Tip[max_size];
		Zauzeto = new bool[max_size];
    brojac = 0;
		for (int i = 0; i < max_size; i++){
			Zauzeto[i] = false;
		}
		
	}
	bool JeLiPun(){
		return brojac == max_size;
	}
	void dodaj(Tip k)
	{
		if (JeLiPun())
			throw exception("greska. Hashset je pun.");
		int i = IzracunajHash(k);

		while (Zauzeto[i])
		{
			i++;
			if (i == max_size)
				i = 0;
		}
		Niz[i] = k;
		Zauzeto[i] = true;
		brojac++;
	}

	bool JeLiPrazan(){
		return brojac == 0;
	}

	bool ukloni(Tip k)
	{
		if (JeLiPrazan())
			return false;

		int i = IzracunajHash(k);
		int b = 0;
		while (b != max_size)
		{
			if (Zauzeto[i])
			{
				if (Niz[i] == k)
				{
					Zauzeto[i] = false;
					cout << "uklonjeno " << k << endl;
					brojac--;
					return true;
				}
			}
			i++;
			b++;
			if (i == n)
				i = 0;
		}
		return false;
	}
	void print(){
		for (int i = 0; i<max_size; i++)
		{
			if (Zauzeto[i])
				cout << i << ": " << Niz[i] << endl;
		}
	}
};
