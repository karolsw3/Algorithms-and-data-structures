/*
* The quick sort algorithm
* Time complexity:
*   Best case: O(n log(n))
*   Worst case: O(n^2)
*   Average: O(n log(n))
* Worst case space complexity: O(n) (naive) / O(log n)
*/

function quickSort (array, left = 0, right = array.length - 1) {
  if (array.length > 1) {
    let index = partition(array, left, right)

    if (left < index - 1) {
      quickSort(array, left, index - 1)
    }

    if (index < right) {
      quickSort(array, index, right)
    }
  }
  return array
}

function partition (array, left = 0, right = array.length - 1) {
  let pivot = array[Math.floor((right + left) / 2)]

  while (left <= right) {
    while (array[left] < pivot) {
      left++
    }

    while (array[right] > pivot) {
      right--
    }

    if (left <= right) {
      swap(array, left, right)
      left++
      right--
    }
  }
  return left
}

function swap (array, firstElement, secondElement) {
  let temp = array[firstElement]
  array[firstElement] = array[secondElement]
  array[secondElement] = temp
}
