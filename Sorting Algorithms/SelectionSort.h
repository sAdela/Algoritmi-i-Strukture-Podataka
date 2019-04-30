#pragma once
template<class T>
void SelectionSort(T niz[], int velicina) {
	int minIndex;
	T temp;
	for (int i = 0; i < velicina - 1; i++) {
		minIndex = i;
		for (int j = i + 1; j < velicina; j++) {
			if (niz[j] < niz[minIndex])
				minIndex = j;
			if (minIndex != i) {
				temp = niz[i];
				niz[i] = niz[minIndex];
				niz[minIndex] = temp;
			}
		}
	}
}
