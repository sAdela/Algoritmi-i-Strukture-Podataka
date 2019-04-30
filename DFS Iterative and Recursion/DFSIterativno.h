#pragma once

#include <iostream>

#include "StekSekv.h"
#include "ListaPov.h"
#include "ListaSekv.h"
using namespace std;

class DfsAlgoritamIterativno{
private:
	int startVrh;
	MatricaSusjedstva* M;

	DfsAlgoritamIterativno(MatricaSusjedstva* M, int startVrh){
		this->M = M;
		this->startVrh = startVrh;
	}

	Lista<int>* _start(){
		this->M = M;
		Lista<int>* posjecen = new ListaSekv<int>(M->velicina);

		StekPov<int> stek;
		stek.dodaj(startVrh);
    
		while (!stek.isPrazan()){
			int v = stek.ukloni();
			if (!posjecen->sadrzi(v)){
				posjecen->dodaj(v);
        
				for (int i = M->velicina - 1; i >= 0; i--){
        
					if (M->isSusjed(v, i))
						if (!posjecen->sadrzi(i))
							stek.dodaj(i);
				}
			}
		}
		return posjecen;
	}

public:
	static Lista<int>* start(MatricaSusjedstva* M, int startVrh = 0){
		return DfsAlgoritamIterativno(M, startVrh)._start();
	}
};
