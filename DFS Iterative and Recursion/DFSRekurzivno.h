#pragma once

#include "ListaSekv.h"
#include "MatricaSusjedstva.h"
using namespace std;

class DfsAlgoritamRekurzija{
private:
	int startVrh;
	MatricaSusjedstva* M;
	Lista<int>* posjecen;

	DfsAlgoritamRekurzija(MatricaSusjedstva* M, int startVrh){
		this->M = M;
		this->posjecen = new ListaSekv<int>;
		this->startVrh = startVrh;
	}

	Lista<int>* _start(){
		Rekurzija(startVrh);
		return posjecen;
	}

	void Rekurzija(int v){
		posjecen->dodaj(v);
		for (int i = 0; i < M->velicina; i++)
			if (M->isSusjed(v, i) && !posjecen->sadrzi(i))
				Rekurzija(i);
	}

public:
	static Lista<int>* start(MatricaSusjedstva* M, int startVrh = 0){
		return DfsAlgoritamRekurzija(M, startVrh)._start();
	}
};
