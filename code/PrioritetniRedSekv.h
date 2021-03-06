#pragma once
#include"PrioritetniRed.h"
template<class T>
class PrioritetniRedSekvencijalni: public PrioritetniRed<T> {
	T* N;
	int brojac; 
	int max;
	void ProsiriPRed() {
		T* temp = new T[max * 2];
		for (int i = 0; i < max; i++)
			temp[i] = N[i];
		delete[] N;
		max *= 2;
		N = temp;
	}
public:
	PrioritetniRedSekvencijalni(int Max = 10) : max(Max) {
		brojac = 0;
		N = new T[max];
	}
	bool JeLiPun() {
		return brojac == max;
	}
	bool JeLiPrazan() {
		return brojac == 0;
	}
	void Dodaj(T x) {
		if (JeLiPun())
			ProsiriPRed();
		N[brojac++] = x;
	}
	T ukloni() {
		if (JeLiPrazan())
			throw exception("Nije moguce ukloniti element iz praznog prioritetnog reda");
		int maxI = 0;
		for (int i = 1; i < brojac; i++) {
			if (N[i] > N[maxI])
				maxI = i;
		}
		brojac--;
		T x = N[maxI];
		N[maxI] = N[brojac];
		return x;
	}

	void Print() {
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
