/**
 * @param {string[]} pizza
 * @param {number} k
 * @return {number}
 */
var ways = function(pizza, k) {
  const hasApple = (i, j) => {
    return pizza[i].charAt(j) === 'A';
  };
  const MOD = Math.pow(10, 9) + 7;

  const rowLen = pizza.length;
  const colLen = pizza[0].length;
  const table = new Array(k).fill(null).map(_ => new Array(rowLen).fill(null).map(_ => new Array(colLen)));

  for (let i = rowLen - 1; i >= 0; i--) {
    for (let j = colLen - 1; j >= 0; j--) {
      const apple = hasApple(i, j);
      const right = apple ? j : Math.min(i === rowLen - 1 ? colLen : table[0][i + 1][j].right, j === colLen - 1 ? colLen : table[0][i][j + 1].right);
      const down = apple ? i : Math.min(i === rowLen - 1 ? rowLen : table[0][i + 1][j].down, j === colLen - 1 ? rowLen : table[0][i][j + 1].down);
      const value = down < rowLen || right < colLen ? 1 : 0;
      table[0][i][j] = {value, right, down};
    }
  }

  for (let ki = 1; ki < k; ki++) {
    for (let i = rowLen - 1; i >= 0; i--) {
      for (let j = colLen - 1; j >= 0; j--) {
        let value = 0;
        const {right, down} = table[0][i][j];
        for (let ii = down + 1; ii < rowLen; ii++) {
          value = (value + table[ki - 1][ii][j].value) % MOD;
        }
        for (let jj = right + 1; jj < colLen; jj++) {
          value = (value + table[ki - 1][i][jj].value) % MOD;
        }
        table[ki][i][j] = {value};
      }
    }
  }

  return table[k - 1][0][0].value;
};

console.log(ways(["A..","AAA","..."], 3));
