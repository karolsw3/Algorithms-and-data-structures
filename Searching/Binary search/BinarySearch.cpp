// A simple binary search implementation written in C++
#include <iostream>

int binarySearch (int number, int array[], unsigned int min, unsigned int max) {
  if (max >= min) {
    unsigned int midpoint = (min + max) / 2;

    if (number > array[midpoint]) {
      return binarySearch(number, array, midpoint + 1, max);
    }
    
    if (number < array[midpoint]) {
      return binarySearch(number, array, min, midpoint - 1);
    }
    
    if (number == array[midpoint]) {
      return midpoint;
    }
  }
  return -1;
}

int main () {
  int array[] = {1, 4, 6, 7, 12, 15, 22, 34, 39, 43, 46, 55, 89, 102, 144, 230, 389, 563, 1039, 5902};
  std::cout << binarySearch(102, array, 0, 20);
  return 1;
}