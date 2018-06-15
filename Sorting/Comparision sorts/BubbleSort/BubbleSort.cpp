#include <iostream>

void bubbleSort(int array[], int n) {
	for (int cycle = 0; cycle < n - 1; cycle++) {
		bool swapped = false;
		for (int pointer = 0; pointer < n - cycle - 1; pointer++) {
			if(array[pointer] > array[pointer + 1]) {
				std::swap(array[pointer], array[pointer + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
	}
}
