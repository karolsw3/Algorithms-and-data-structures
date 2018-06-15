#include <iostream>
#include <vector>

int partition (int *A, int min, int max) {
	int center = (min + max) / 2;
	int pivot = A[center];
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

int main () {
	int A[] = {1, 3, 12, 3, 2, 1, 8, 1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 12};
	quickSort(A, 0, 17);
	for (int i = 0; i < 17; i++) {
		std::cout << "Array[" << i << "] = " << A[i] << ";" << std::endl;
	}
	return 0;
}
