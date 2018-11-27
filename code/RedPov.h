#pragma once
#include"Cvor.h"

template <class T>
class RedPovezani {
	Cvor<T>* pocetak;
	Cvor<T>* kraj;
public:
	RedPovezani() {
		pocetak = nullptr; kraj = nullptr;
	}
	bool JeLiPrazan() {
		return pocetak == nullptr;
	}
	void Dodaj(T x) {
		Cvor<T> *temp = new Cvor<T>(x, nullptr);
		if (pocetak == nullptr) {
			pocetak = temp;
			kraj = temp;
		}
		else {
			kraj->next = temp;
			kraj = temp;
		}
	}

	T ukloni() {
		if (JeLiPrazan())
			throw exception("Nije moguce ukloniti element iz praznog reda");
		Cvor<T> *temp = pocetak;
		pocetak = pocetak->next;
		T x = temp->info;

		delete temp;

		if (pocetak == nullptr)
			kraj = nullptr;

		return x;
	}

	bool sadrzi(T x) {
		Cvor<T>* temp = pocetak;
		while (temp != nullptr) {
			if (temp->info == x)
				return true;
			temp = temp->next;
		}
		return false;
	}
	
	void print() {
		Cvor<T>* temp = pocetak;
		while (temp != nullptr) {
			cout << temp->info << " ";
			temp = temp->next;
		}
		cout << endl;
	}

};
