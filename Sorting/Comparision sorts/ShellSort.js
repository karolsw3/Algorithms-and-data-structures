/*
* The shell sort algorithm
* Time complexity:
*   Best case: O(n log n)
*   Worst case: O(n^2)
*   Average: O(n^(5/4))
*            O(n^(3/2))
*   Worst case space complexity: О(n) total, O(1) auxiliary
*/

function shellSort (array) {
  for (let gap = Math.floor(array.length / 2); gap > 0; gap = Math.floor(gap / 2)) {
    for (let i = gap; i < array.length; i++) {
      let temp = array[i]
      for (var j = i; j >= gap && array[j - gap] > temp; j -= gap) {
        array[j] = array[j - gap]
      }
      array[j] = temp
    }
  }
  return array
}
