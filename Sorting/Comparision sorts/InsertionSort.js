/*
* The insertion sort algorithm
* Time complexity:
*   Best case: O(n)
*   Worst case: O(n^2)
*   Average: O(n^2)
* Space complexity: O(n)
*/

function insertionSort (array) {
  for (let i = 1; i < array.length; i++) {
    let temp = array[i]
    for (var j = i - 1; j > -1 && array[j] > temp; j--) {
      array[j + 1] = array[j]
    }
    array[j + 1] = temp
  }
  return array
}
