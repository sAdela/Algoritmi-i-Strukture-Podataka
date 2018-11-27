#pragma once
#include"Cvor.h"

template<class T>
class PrioritetniRedPovezani {
	Cvor<T>* prvi;
public:
	PrioritetniRedPovezani() {
		prvi = nullptr;
	}
	
	bool JeLiPrazan() {
		return prvi == nullptr;
	}

	void Dodaj(T x) {
		Cvor<T>* temp = prvi;
		Cvor<T>* pretT = nullptr;
		while (temp != nullptr) {
			if (temp->info < x)
				break;
			pretT = temp;
			temp = temp->next;
		}
		Cvor<T>* novi = new Cvor<T>(x, temp);
		if (pretT == nullptr) {
			prvi = novi;
		}
		else {
			pretT->next = novi;
		}
	}

	T Ukloni() {
		if (JeLiPrazan())
			throw exception("Nije moguce ukloniti element iz praznog prioritetnog reda");
		Cvor<T>* temp = prvi;
		prvi = prvi->next;
		T x = temp->info;
		
		delete temp;
		return x;
	}

	void Print() {
		Cvor<T>* temp = prvi;
		while (temp != nullptr) {
			cout << temp->info << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	bool Sadrzi(T x) {
		Cvor<T>* temp = prvi;
		while (temp != nullptr) {
			if (temp->info == x)
				return true;
			temp = temp->next;
		}
		return false;
	}

};
