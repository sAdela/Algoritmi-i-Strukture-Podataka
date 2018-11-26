#pragma once

template<class T>
class RedSekvencijalni {
	int pocetak; 
	int kraj;
	int brojac;
	int max;
	T* N;
	void ProsiriRed() {
		T* temp = new T[max * 2];
		int j = pocetak;
		for (int i = 0; i < brojac; i++) {
			temp[i] = N[pocetak++];
			if (pocetak == max)
				pocetak = 0;
		}
		delete[] N;
		max *= 2;
		pocetak = 0;
		kraj = brojac;
		N = temp;
	}

public:
	RedSekvencijalni(int Max = 10) :pocetak(0), kraj(0), brojac(0), max(Max) {
		N = new T[max];
	}

	bool JeLiPrazan() {
		return brojac == 0;
	}
	bool JeLiPun() {
		return brojac == max;
	}
	void Dodaj(T x) {
		if (JeLiPun())
			ProsiriRed();

		N[kraj++] = x;
		brojac++;

		if (kraj == max)
			kraj = 0;
	}
	T ukloni() {
		if (JeLiPrazan())
			throw exception("Nije moguce ukloniti element iz praznog reda");
		T x = N[pocetak++];
		if (pocetak == max)
			pocetak = 0;

		brojac--;
		return x;
	}

	void Print() {
		int j = pocetak;
		for (int i = 0; i < brojac; i++) {
			cout << N[j++] << " ";
			if (j == max)
				j = 0;
		}
	}
	
	bool sadrzi(T x) {
		int j = pocetak;
		for (int i = 0; i < brojac; i++) {
			if (N[j++] == x)
				return true;
			if (j == max)
				j = 0;
		}
		return false;
	}
};
