#pragma once
#include"Cvor.h"
#include"Stek.h"
template<class T>
class StekPovezani: public Stek<T> {
	Cvor<T> *prvi;
public:
	StekPovezani() {
		prvi = nullptr;
	}

	bool JeLiPrazan() {
		return prvi == nullptr;
	}

	void Dodaj(T x) {
		Cvor<T> *temp = new Cvor<T>(x, prvi);
		prvi = temp;
	}

	T ukloni() {
		if (JeLiPrazan())
			throw exception("Ne moze se ukloniti element iz praznog steka");

		Cvor<T> *temp = prvi;
		T x = temp->info;

		prvi = prvi->next;

		delete temp;
		return x;
	}

	T vrh() {
		if (JeLiPrazan())
			throw exception("Stek je prazan");
		return prvi->info;
	}

	void print() {
		Cvor<T>* temp = prvi;
		while (temp != nullptr) {
			cout << temp->info << " ";
			temp = temp->next;
		}
	}

	bool sadrzi(T x) {
		Cvor<T>* temp = prvi;
		while (temp != nullptr) {
			if (temp->info == x)
				return true;
			temp = temp->next;
		}
		return false;
	}

};
