/*
* The bubble sort algorithm
* Time complexity: O(n^2)
*   Best case: O(n)
*   Worst case: O(n^2)
*   Average: O(n^2)
* Space complexity: O(1)
*/

function bubbleSort (array) {
  for (let i = array.length; i > 0; i--) {
    let swapped = false
    for (let j = 0; j < i; j++) {
      if (array[j + 1] < array[j]) {
        let temp = array[j + 1]
        array[j + 1] = array[j]
        array[j] = temp
        swapped = true
      }
    }
    if (!swapped) break
  }
  return array
}
