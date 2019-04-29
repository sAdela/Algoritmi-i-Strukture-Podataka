template <class T>
void InsertionSort(T niz[], int velicina) {
	for (int i = 1; i < velicina; i++) {
		int j = i;
		while (j > 0 && niz[j - 1] > niz[j]) {
			T pom = niz[j - 1];
			niz[j - 1] = niz[j];
			niz[j] = pom;
			j--;
		}
	}
}
