/**
 * @param {string[][]} paths
 * @return {string}
 */
var destCity = function(paths) {
  const hasOut = new Set();
  const noOut = new Set();
  for (const [c1, c2] of paths) {
    if (!hasOut.has(c2)) {
      noOut.add(c2);
    }
    if (noOut.has(c1)) {
      noOut.delete(c1);
    }
    hasOut.add(c1);
  }
  const it = noOut.values();
  return it.next().value;
};

const test = [];
test.push([["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]);

for (t of test) {
  console.log(destCity(t));
}
