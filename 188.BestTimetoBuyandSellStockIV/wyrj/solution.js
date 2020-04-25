/**
 * @param {number} k
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(k, prices) {
  if (k === 0) {
    return 0;
  }
  let findMin = true;
  const simple = [];

  for (let i = 0; i < prices.length; i++) {
    if (findMin && i < prices.length - 1 && prices[i] < prices[i + 1]) {
      simple.push(prices[i]);
      findMin = false;
    } else if(!findMin && (i === prices.length - 1 || prices[i] > prices[i + 1])) {
      simple.push(prices[i]);
      findMin = true;
    }
  }

  if (simple.length === 0) {
    return 0;
  }

  const segments = [];
  for (let i = 0; i < simple.length; i+=2) {
    segments.push({low: simple[i], high: simple[i + 1]});
  }

  if (k >= segments.length) {
    return segments.reduce((v, {low, high}) => {
      return v + high - low;
    }, 0);
  }

  const table = new Array(k);
  for (let i = 0; i < k; i++) {
    table[i] = new Array(segments.length);
    let localLow = Number.MAX_SAFE_INTEGER;
    for (let j = i; j < segments.length; j++) {
      let {low, high} = segments[j];
      low = Math.min(low, localLow);
      const indiValue = (i === 0 ? 0 : table[i - 1][j - 1].value) + high - low;
      const skipValue = i === j ? 0 : table[i][j - 1].value;
      const mergeValue = i === j ? 0 : table[i][j - 1].value + high - table[i][j - 1].high;
      let value;

      if (indiValue >= skipValue && indiValue >= mergeValue) {
        value = indiValue;
        localLow = Number.MAX_SAFE_INTEGER;
      } else if (mergeValue > skipValue) {
        value = mergeValue;
        low = table[i][j - 1].low;
        localLow = Number.MAX_SAFE_INTEGER;
      } else {
        localLow = Math.min(localLow, low);
        value = skipValue;
        low = table[i][j - 1].low;
        high = table[i][j - 1].high;
      }
      table[i][j] = {
        value,
        low,
        high,
      }
    }
  }
  return table[k - 1][segments.length - 1].value;
};

// console.log(maxProfit(1, [0,1,2,1,3,4,2,1,2,4]));
// console.log(maxProfit(2, [0,1,2,1,3,4,2,1,2,4]));
// console.log(maxProfit(3, [0,1,2,1,3,4,2,1,2,4]));
// console.log(maxProfit(2,[70,4,83,56,94,72,78,43,2,86,65,100,94,56,41,66,3,33,10,3,45,94,15,12,78,60,58]));
// console.log(maxProfit(2,[4,83,56,94,72,78,2,86,65,100,41,66,3,33,3,94,12,78]));
console.log(maxProfit(2,[4,94,2,86,65,100,3,94]));
console.log(maxProfit(29, [70,4,83,56,94,72,78,43,2,86,65,100,94,56,41,66,3,33,10,3,45,94,15,12,78,60,58,0,58,15,21,7,11,41,12,96,83,77,47,62,27,19,40,63,30,4,77,52,17,57,21,66,63,29,51,40,37,6,44,42,92,16,64,33,31,51,36,0,29,95,92,35,66,91,19,21,100,95,40,61,15,83,31,55,59,84,21,99,45,64,90,25,40,6,41,5,25,52,59,61,51,37,92,90,20,20,96,66,79,28,83,60,91,30,52,55,1,99,8,68,14,84,59,5,34,93,25,10,93,21,35,66,88,20,97,25,63,80,20,86,33,53,43,86,53,55,61,77,9,2,56,78,43,19,68,69,49,1,6,5,82,46,24,33,85,24,56,51,45,100,94,26,15,33,35,59,25,65,32,26,93,73,0,40,92,56,76,18,2,45,64,66,64,39,77,1,55,90,10,27,85,40,95,78,39,40,62,30,12,57,84,95,86,57,41,52,77,17,9,15,33,17,68,63,59,40,5,63,30,86,57,5,55,47,0,92,95,100,25,79,84,93,83,93,18,20,32,63,65,56,68,7,31,100,88,93,11,43,20,13,54,34,29,90,50,24,13,44,89,57,65,95,58,32,67,38,2,41,4,63,56,88,39,57,10,1,97,98,25,45,96,35,22,0,37,74,98,14,37,77,54,40,17,9,28,83,13,92,3,8,60,52,64,8,87,77,96,70,61,3,96,83,56,5,99,81,94,3,38,91,55,83,15,30,39,54,79,55,86,85,32,27,20,74,91,99,100,46,69,77,34,97,0,50,51,21,12,3,84,84,48,69,94,28,64,36,70,34,70,11,89,58,6,90,86,4,97,63,10,37,48,68,30,29,53,4,91,7,56,63,22,93,69,93,1,85,11,20,41,36,66,67,57,76,85,37,80,99,63,23,71,11,73,41,48,54,61,49,91,97,60,38,99,8,17,2,5,56,3,69,90,62,75,76,55,71,83,34,2,36,56,40,15,62,39,78,7,37,58,22,64,59,80,16,2,34,83,43,40,39,38,35,89,72,56,77,78,14,45]));
