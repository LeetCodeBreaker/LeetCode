/**
 * @param {number[]} arr
 * @return {number}
 */
var countTriplets = function(arr) {
  const table = new Array(arr.length).fill(null).map(_ => new Array(arr.length));
  for (let i = 0; i < arr.length; i++) {
    let now = 0;
    for (let j = i; j < arr.length; j++) {
      now = now ^ arr[j];
      table[i][j] = now;
    }
  }

  let count = 0;
  for (let i = 0; i < arr.length; i++) {
    for (let j = i + 1; j < arr.length; j++) {
      for (let k = j; k < arr.length; k++) {
        if (table[i][j - 1] === table[j][k]) {
          count += 1;
        }
      }
    }
  }
  return count;
};

console.log(countTriplets([2,3,1,6,7]));
