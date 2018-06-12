#include <iostream>
#include <vector>

void merge (std::vector<int> &left, std::vector<int> &right, std::vector<int> &array) {
	std::vector<int> output;
	while (left.size() > 0 && right.size() > 0) {
		if (left[0] < right[0]) {
			output.push_back(left[0]);
			left.erase(left.begin());
		} else {
			output.push_back(right[0]);
			right.erase(right.begin());
		}
	}
	
	while (left.size() > 0) {
		output.push_back(left[0]);
		left.erase(left.begin());
	}
	
	while(right.size() > 0) {
		output.push_back(right[0]);
		right.erase(right.begin());
	}
	
	for (unsigned int i = 0; i < array.size(); i++) {
		array[i] = output[i];
	}
}

void mergeSort (std::vector<int> &array) {
	if (array.size() == 1) {
		return;
	} else {
		std::vector<int> left(array.begin(), array.end() - array.size() / 2);
		std::vector<int> right(array.begin() + array.size() / 2, array.end());
		
		mergeSort(left);
		mergeSort(right);
		
		merge(left, right, array);
	}
}

