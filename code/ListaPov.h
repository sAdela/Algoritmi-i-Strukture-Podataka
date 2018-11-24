#pragma once
#include"Cvor.h"
template<class Tip>
class ListaPovezana {
	Cvor<Tip>* prvi;

public:
	ListaPovezana(): prvi(nullptr) {}

	void Dodaj(Tip x) {
		Cvor<Tip>* novi = new Cvor<Tip>(x, prvi);
		prvi = novi;
	}

	Tip Ukloni() {
		if (isPrazan())
			throw exception("Nije moguce ukloniti element iz praznog niza");
		Cvor<Tip> *t = prvi;
		prvi = prvi->next;
		Tip x = t->info;
		delete t;
		return x;
	}

	bool isPrazan() {
		return prvi == nullptr;
	}

	void Print() {
		Cvor<Tip> *t = prvi;
		while (t!= nullptr) {
			cout << t->info << " ";
			t = t->next;
		}
		cout << endl;
	}

	int count() {
		Cvor<Tip> *t = prvi;
		int brojac = 0;
		while (t != nullptr) {
			brojac++;
			t = t->next;
		}
		return brojac;
	}
	bool sadrzi(const Tip& x) {
		Cvor<Tip>* t = prvi;
		while (t != nullptr) {
			if (t->info == x)
				return true;
			t = t->next;			
		}
		return false;
	}

	Tip& operator[](const int& i) {
		Cvor<Tip>*t = prvi;
		int brojac = 0;
		while (t != nullptr) {
			if (i == brojac)
				return t->info;
			brojac++;
			t = t->next;
		}
		throw exception("Ne postoji toliko elemenata u nizu");
	}
	
};
