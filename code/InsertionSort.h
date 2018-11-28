template <class T>
void InsertionSort(T niz[], int brojac) {
	for (int i = 1; i < brojac; i++) {
		int j = i;
		while (j > 0 && niz[j - 1] > niz[j]) {
			T pom = niz[j - 1];
			niz[j - 1] = niz[j];
			niz[j] = pom;
			j--;
		}
	}
}
