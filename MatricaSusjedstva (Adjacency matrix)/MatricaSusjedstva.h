#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "ListaPov.h"
#include "ListaSekv.h"
#include "Ivica.h"
using namespace std;

class MatricaSusjedstva {
	int **matrica;
	int velicina;
public:
	MatricaSusjedstva(int vel = 10) {
		velicina = vel;
		matrica = new int*[velicina];
		for (int i = 0; i < velicina; i++) {
			matrica[i] = new int[velicina];
			for (int j = 0; j < velicina; j++)
				matrica[i][j] = 0;
		}
	}

	void Ucitaj(string nazivFajla) {
		int varijabla;
		ifstream fajl(nazivFajla);
		for (int i=0; i<velicina; i++)
			for (int j = 0; j < velicina; j++) {
				fajl >> varijabla;
				matrica[i][j] = varijabla;
			}
		fajl.close();
	}

	bool JelSusjed(int from, int to) {
		return matrica[from][to] != 0;
	}

	ListaPov<int> SusjediTo(int x) {
		ListaPov<int> lista = new ListaPov<int>;
		for (int i = 0; i < velicina; i++) {
			if (JelSusjed(i, x))
				lista->dodaj(i);
		}
		return lista;
	}

	ListaPov<int> SusjediFrom(int x) {
		ListaPov<int> lista = new ListaPov<int>;
		for (int i = 0; i < velicina; i++)
			if (JelSusjed(x, i))
				lista->dodajnakraj(i);
		return lista;
	}

	int UlazniStepen(int x) {
		int suma = 0;
		for (int i = 0; i < velicina; i++)
			suma += matrica[i][x];
		return suma;
	}
	int IzlazniStepen(int x) {
		int suma = 0;
		for (int i = 0; i < velicina; i++) {
			suma += matrica[x][i];
		}
		return suma;
	}
	int tezina(int from, int to) {
		return matrica[from][to];
	}
	int najbliziSusjedTo(int x) {
		Lista<int>* lista = SusjediTo(x);
		int minI = 0;
		int minV = INT_MAX;
		while(!lista.isPrazna()){
			int s = susjedi->uklonisakraja();
			int t = tezina(s, x);
			if (t < minV) {
				minV = t;
				minI = s;
			}
		}
		return minI;
	}

	int IzlazniStepenMax() {
		int maxI = 0; 
		int maxV = IzlazniStepen(maxI);
		for (int i = 1; i < velicina; i++) {
			int t = IzlazniStepen(i);
			if (maxV < t) {
				maxV = t;
				maxI = i;
			}
		}
		return maxI;
	}

	int UlazniStepenMax() {
		int maxI = 0;
		int maxV = UlazniStepen(maxI);
		for (int i = 1; i < velicina; i++) {
			int t = UlazniStepen(i);
			if (maxV < t) {
				maxV = t;
				maxI = i;
			}
		}
		return maxI;
	}
};
