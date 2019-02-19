#pragma once
#include"Stek.h"
template<class T>
class StekSekvencijalni: public Stek<T> {
	int brojac;
	int max; 
	T* N;

	void ProsiriNiz() {
		T* temp = new T[max * 2];
		for (int i = 0; i < max; i++) {
			temp[i] = N[i];
		}
		delete[] N;
		max *= 2;
		N = temp;
	}

public:
	StekSekv(int Max = 10) :max(Max), brojac(0) {
		N = new T[max];
	}

	void Dodaj(T x) {
		if (JeLiPun())
			ProsiriNiz();
		N[brojac++] = x;
	}
	bool JeLiPun() {
		return brojac == max;
	}
	bool JeLiPrazan() {
		return brojac == 0;
	}

	T ukloni() {
		if (JeLiPrazan())
			throw exception("Ne moze se ukloniti element iz praznog steka");
		T temp = N[--brojac];
		return temp;
	}

	T vrh() {
		if (JeLiPrazan())
			throw exception("Stek je prazan");
		return N[brojac - 1];
	}

	void print() {
		for (int i = 0; i < brojac; i++)
			cout << N[i] << " ";
		cout << endl;
	}

	bool sadrzi(T x) {
		for (int i = 0; i < brojac; i++)
			if (N[i] == x)
				return true;
		return false;
	}
};
