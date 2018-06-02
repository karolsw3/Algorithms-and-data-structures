/*
* The merge sort algorithm
* Time complexity: O(n log(n))
*/

function mergeSort (array) {
  if (array.length === 1) {
    return array
  } else {
    let left = array.slice(0, array.length / 2)
    let right = array.slice(array.length / 2)

    left = mergeSort(left)
    right = mergeSort(right)

    return merge(left, right)
  }
}

function merge (arrayA, arrayB) {
  let c = []
  while (typeof arrayA !== 'undefined' && arrayA.length > 0 && typeof arrayB !== 'undefined' && arrayB.length > 0) {
    if (arrayA[0] > arrayB[0]) {
      c.push(arrayB[0])
      arrayB.shift()
    } else {
      c.push(arrayA[0])
      arrayA.shift()
    }
  }

  while (typeof arrayA !== 'undefined' && arrayA.length > 0) {
    c.push(arrayA[0])
    arrayA.shift()
  }

  while (typeof arrayB !== 'undefined' && arrayB.length > 0) {
    c.push(arrayB[0])
    arrayB.shift()
  }

  return c
}
