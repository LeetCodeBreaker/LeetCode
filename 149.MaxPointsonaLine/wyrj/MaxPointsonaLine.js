/**
 * @param {number[][]} points
 * @return {number}
 */
var maxPoints = function(points) {
  if (points.length < 3) {
    return points.length;
  }
  const map = new Map();
  let max = 0;

  const gcd = (a, b) => {
    if (a < b) {
      return gcd(b, a);
    }
    if (b === 0) {
      return a;
    }
    return gcd(b, a % b);
  };

  const count = (key1, key2, x, y1, y2) => {
    let m = map;
    if (!m.has(key1)) {
      m.set(key1, new Map());
    }
    m = m.get(key1);
    if (!m.has(key2)) {
      m.set(key2, new Map());
    }
    m = m.get(key2);
    if (!m.has(x)) {
      m.set(x, new Set());
    }
    let s = m.get(x);
    s.add(y1);
    s.add(y2);
    max = Math.max(max, s.size);
  };

  const size = points.length;
  for (let i = 0; i < size; i++) {
    for (let j = i + 1; j < size; j++) {
      const [x1, y1] = points[i];
      const [x2, y2] = points[j];
      if (x1 === x2) {
        count('-', '-', x1, i, j);
      } else if (y1 === y2) {
        count(0, 0, y1, i, j);
      } else {
        const diffX = x2 - x1;
        const diffY = y2 - y1;
        const g = gcd(Math.abs(diffX), Math.abs(diffY));
        const neg = diffX * diffY < 0;
        count(Math.abs(diffX / g) * (neg ? -1 : 1), Math.abs(diffY / g), x2 - diffX * y2 / diffY, i, j);
      }
    }
  }

  return max;
};

console.log(maxPoints([[1,1],[2,2],[3,3]]));
console.log(maxPoints([[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]));
console.log(maxPoints([[0,0],[1,1],[0,0]]));
