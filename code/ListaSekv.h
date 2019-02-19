#pragma once 

template<class Tip>
class ListaSekvencijalna {
	Tip* N;
	int brojac; 
	int max;
  
	void ProsiriNiz() {
		Tip* temp = new Tip[max * 2];
		for (int i = 0; i < max; i++) 
			temp[i] = N[i];
		delete[] N;
		max = max * 2;
		N = temp;
	}
  
public:
	ListaSekvencijalna(int Max=10) :brojac(0), max(Max) {
		N = new Tip[max];
	}
  
	void Dodaj(Tip x) {
		if (isPun())
			ProsiriNiz();
      
		N[brojac++] = x;
	}
  
	Tip Ukloni() {
		if (isPrazan())
			throw exception("Nije moguce ukloniti element iz praznog niza");
      
		Tip x = N[--brojac];
		return x;
	}
  
	bool isPrazan() {
		return brojac == 0;
	}
  
	bool isPun() {
		return brojac == max;
	}
	
	int count(){
		return brojac;
	}
  
	void Print() {
		for (int i = 0; i < brojac; i++)
			cout << N[i] << " ";
		cout << endl;
	}
  
	Tip& operator[](const int& i) {
		if (i > brojac)
			throw exception("Ne postoji element na toj lokaciji");
      
		return N[i];
	}
  
	Tip* getNiz() {
		return N;
	}
  
	bool sadrzi(const Tip &x) {
		for (int i = 0; i < brojac; i++) 
			if (N[i] == x)
				return true;
		
		return false;
	}
  
};
