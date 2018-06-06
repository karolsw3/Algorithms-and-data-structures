/*
* The heap sort algorithm
* Time complexity:
*   Best case: O(n log(n)) (different keys) / O(n) (equal keys)
*   Worst case: O(n log(n))
*   Average: O(n log(n))
* Space complexity: O(1)
*/

function heapSort (array) {
  buildMaxHeap(array)
  let lastElementIndex = array.length - 1

  while (lastElementIndex > 0) {
    swap(array, 0, lastElementIndex)
    heapify(array, 0, lastElementIndex)

    lastElementIndex -= 1
  }

  return array
}

function buildMaxHeap (array) {
  let i = Math.floor(array.length / 2 - 1)

  while (i >= 0) {
    heapify(array, i, array.length)
    i -= 1
  }
}

function heapify (array, i, max) {
  let index
  let leftChild
  let rightChild

  while (i < max) {
    index = i

    leftChild = 2 * i + 1
    rightChild = leftChild + 1

    if (leftChild < max && array[leftChild] > array[index]) {
      index = leftChild
    }

    if (rightChild < max && array[rightChild] > array[index]) {
      index = rightChild
    }

    if (index === i) {
      return
    }

    swap(array, i, index)
    i = index
  }
}

function swap (array, firstElement, secondElement) {
  let temp = array[firstElement]
  array[firstElement] = array[secondElement]
  array[secondElement] = temp
}

// Practice

function heapSort (array) {
  buildMaxHeap(array)

  let lastElementIndex = array.length - 1

  while (lastElementIndex > 0) {
    
  }
}

function buildMaxHeap (array) {
  let parent = Math.floor(array.length / 2 - 1)
  while (parent >= 0) {
    heapify(array, parent, array.length)
    parent--
  }
}

function heapify (array, parent, max) {
  while (parent > max) {
    let index = parent
    let leftChild = parent * 2 + 1
    let rightChild = leftChild + 1

    if (leftChild > max && array[leftChild] > array[index]) {
      index = leftChild
    }

    if (rightChild > max && array[rightChild] > array[index]) {
      index = rightChild
    }

    if (parent !== index) {
      swap(array, parent, index)
      index = parent
    }
    parent--
  }
}

function swap (array, firstElement, secondElement) {
  let temp = array[firstElement]
  array[firstElement] = array[secondElement]
  array[secondElement] = temp
}
