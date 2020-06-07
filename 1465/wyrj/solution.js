/**
 * @param {number} h
 * @param {number} w
 * @param {number[]} horizontalCuts
 * @param {number[]} verticalCuts
 * @return {number}
 */
var maxArea = function(h, w, horizontalCuts, verticalCuts) {
  const findMax = (size, cuts) => {
    let last = 0;
    let max = 0;
    cuts.sort((lhs, rhs) => {
      return lhs - rhs;
    });
    for (let c of cuts) {
      max = Math.max(c - last, max);
      last = c;
    }
    return Math.max(size - last, max);
  };

  return (findMax(h, horizontalCuts) * findMax(w, verticalCuts)) % (10**9 + 7);
};

console.log(maxArea(5,4,[1,2,4],[1,3]));
console.log(maxArea(5,4,[3,1],[1]));
