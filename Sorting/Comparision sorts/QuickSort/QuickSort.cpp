#include <iostream>
#include <vector>

int partition (int *A, int min, int max) {
	int pivot = A[min];
	int i = min - 1;
	int j = max + 1;
	for (;;) {
		do {
			i++;
		} while (A[i] < pivot);

		do {
			j--;
		} while (A[j] > pivot);

		if (i >= j) {
			return j;
		}

		std::swap(A[i], A[j]);
	}
}

void quickSort (int *A, int min, int max) {
	if (min < max) {
		int p = partition(A, min, max);
		quickSort(A, min, p);
		quickSort(A, p + 1, max);
	}
}

