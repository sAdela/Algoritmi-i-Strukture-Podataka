#pragma once

#include <iostream>
#include "RedPov.h"
#include "RedSekv.h"
#include "ListaPov.h"
#include "ListaSekv.h"
using namespace std;

class BfsAlgoritamIterativno{
private:
	int startVrh;
	MatricaSusjedstva* M;

	BfsAlgoritamIterativno(MatricaSusjedstva* M, int startVrh){
		this->M = M;
		this->startVrh = startVrh;
	}

	Lista<int>* _start(){
		this->M = M;
		Lista<int>* posjecen = new ListaSekv<int>(M->velicina);

		RedPov<int> red;
		red.dodaj(startVrh);
		while (!red.isPrazan()){
			int v = red.ukloni();

			if (!posjecen->sadrzi(v)){
				posjecen->dodaj(v);

				for (int i = 0; i < M->velicina; i++){
					if (M->isSusjed(v, i))
						if (!red.sadrzi(i) && !posjecen->sadrzi(i))
							red.dodaj(i);
				}
			}
		}
		return posjecen;
	}

public:
	static Lista<int>* start(MatricaSusjedstva* M, int startVrh = 0){
		return BfsAlgoritamIterativno(M, startVrh)._start();
	}
};
