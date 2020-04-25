/**
 * @param {number[][]} dungeon
 * @return {number}
 */
var calculateMinimumHP = function(dungeon) {
  const rLen = dungeon.length;
  const cLen = rLen && dungeon[0].length;

  const table = new Array(rLen);

  for (let i = rLen - 1; i >= 0; i--) {
    table[i] = new Array(cLen);
    for (let j = cLen - 1; j >= 0; j--) {
      if (i === rLen - 1 && j === cLen - 1) {
        table[i][j] = Math.max(0, -dungeon[i][j]);
      } else {
        const rightNeed = j === cLen - 1 ? Number.MAX_SAFE_INTEGER : table[i][j + 1];
        const downNeed = i === rLen - 1 ? Number.MAX_SAFE_INTEGER : table[i + 1][j];
        table[i][j] = Math.max(0, -dungeon[i][j] + Math.min(rightNeed, downNeed));
      }
    }
  }
  return table[0][0] + 1;
};

console.log(calculateMinimumHP([
  [-2, -3, 3],
  [-5, -10, 1],
  [10, 30, -5]
]));
