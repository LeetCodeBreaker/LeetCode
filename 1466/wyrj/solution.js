/**
 * @param {number} n
 * @param {number[][]} connections
 * @return {number}
 */
var minReorder = function(n, connections) {
  const nodes = new Array(n).fill(null).map(() => {
    return {
      inDir: new Set(),
      outDir: new Set(),
    };
  });
  for (const c of connections) {
    nodes[c[0]].outDir.add(c[1]);
    nodes[c[1]].inDir.add(c[0]);
  }

  const q = [0];
  const seen = new Set(q);
  let i = 0;
  let change = 0;
  while (i < q.length) {
    const city = nodes[q[i]];
    for (const [o] of city.inDir.entries()) {
      if (seen.has(o)) {
        continue;
      }
      seen.add(o);
      q.push(o);
    }
    for (const [o] of city.outDir.entries()) {
      if (seen.has(o)) {
        continue;
      }
      seen.add(o);
      q.push(o);
      change += 1;
    }
    i += 1;
  }
  return change;
};

console.log(minReorder(6, [[0,1],[1,3],[2,3],[4,0],[4,5]]));
