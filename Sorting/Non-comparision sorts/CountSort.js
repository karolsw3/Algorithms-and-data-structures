/*
* The count sort algorithm
* Time complexity: O(n + k)
* Space complexity: O(n + k)
*/

function countSort (array) {
  let keyValuesCount = Array(array.length - 1).fill(0)
  let result = Array(array.length - 1).fill(null)

  for (let i = 0; i < array.length; i++) {
    keyValuesCount[array[i]]++
  }

  for (let i = 1; i < keyValuesCount.length; i++) {
    keyValuesCount[i] += keyValuesCount[i - 1]
  }

  for (let i = 0; i < array.length; i++) {
    result[keyValuesCount[array[i]] - 1] = array[i]
    keyValuesCount[array[i]]--
  }

  return result
}
