#pragma once
#include "PrioritetniRed.h"
template<class T>
class PrioritetniRedHeap: public PrioritetniRed<T> {
	T* N;
	int brojac;
	int max;
	int GetPozLijevoDijete(int i) {
		return i * 2;
	}
	int GetPozDesnoDijete(int i) {
		return i * 2 + 1;
	}
	int GetPozRoditelj(int i) {
		return i / 2;
	}
	bool JeLiImaLijevoDijete(int i) {
		return GetPozLijevoDijete(i) <= brojac;
	}
	bool JeLiImaDesnoDijete(int i) {
		return GetPozDesnoDijete(i) <= brojac;
	}
	bool JeLiKorijen(int i) {
		return i == 1;
	}
	bool JeLiList(int i) {
		return !JeLiImaLijevoDijete(i);
	}
	void Rotiraj(int i, int j) {
		T temp = N[i];
		N[i] = N[j];
		N[j] = temp;
	}

	void BubbleDown(int i) {
		if (JeLiList(i))
			return;

		int maxI = i;
		int LD = GetPozLijevoDijete(i);

		if (N[LD] > N[maxI])
			maxI = LD;
		if (JeLiImaDesnoDijete(i)) {
			int DD = GetPozDesnoDijete(i);
			if (N[DD] > N[maxI])
				maxI = DD;
		}
		if (maxI != i) {
			Rotiraj(maxI, i);
			BubbleDown(maxI);
		}
	}

	void BubbleUp(int i) {
		if (JeLiKorijen(i))
			return;
		int r = GetPozRoditelj(i);
		if (N[r] < N[i]) {
			Rotiraj(r, i);
			BubbleUp(r);
		}
	}

	void ProsiriPR() {
		T* temp = new T[max * 2];
		for (int i = 0; i < max; i++)
			temp[i] = N[i];
		delete[] N;
		max *= 2;
		N = temp;
	}

public:
	PrioritetniRedHeap(int Max=10):max(Max), brojac(0) {
		N = new T[max+1];
	}

	bool JeLiPrazan() {
		return brojac == 0;
	}
	bool JeLiPun() {
		return brojac == max - 1;
	}

	void Dodaj(T x) {
		if (JeLiPun())
			ProsiriPR();
		N[++brojac] = x;
		BubbleUp(brojac);
	}

	T Ukloni() {
		if (JeLiPrazan())
			throw exception("Ne moze se ukloniti element iz praznog prior. heap reda");
		T x = N[1];
		N[1] = N[brojac--];
		BubbleDown(brojac);
		return x;
	}

	void Print() {
		for (int i = 1; i <= brojac; i++)
			cout << N[i] << " ";
		cout << endl;
	}

};
