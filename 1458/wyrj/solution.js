/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxDotProduct = function(nums1, nums2) {

  const table = new Array(nums1.length).fill(null).map(_ => new Array(nums2.length));
  for (let i1 = 0; i1 < nums1.length; i1++) {
    for (let i2 = 0; i2 < nums2.length; i2++) {
      const candidate = [((i1 > 0 && i2 > 0) ? Math.max(table[i1 - 1][i2 - 1], 0) : 0) + nums1[i1] * nums2[i2]];
      if (i1 > 0) {
        candidate.push(table[i1 - 1][i2]);
      }
      if (i2 > 0) {
        candidate.push(table[i1][i2 - 1]);
      }
      table[i1][i2] = Math.max(...candidate);
    }
  }

  return table[nums1.length - 1][nums2.length - 1];
};

console.log(maxDotProduct(
  [-3,-8,3,-10,1,3,9],
  [9,2,3,7,-9,1,-8,5,-1,-1]
));
