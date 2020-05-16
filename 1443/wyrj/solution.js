/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {boolean[]} hasApple
 * @return {number}
 */
var minTime = function(n, edges, hasApple) {
  const nodes = new Array(n).fill(null).map((_, index) => {
    return {
      index,
      nb: new Set(),
      depth: index === 0 ? 0 : -1,
      parent: -1,
      apple: hasApple[index],
      need: 0,
    };
  });

  for (const [a, b] of edges) {
    nodes[a].nb.add(b);
    nodes[b].nb.add(a);
  }

  const bfsQ = [nodes[0]];
  for (let i = 0; i < bfsQ.length; i++) {
    for (const ni of bfsQ[i].nb.values()) {
      if (nodes[ni].depth >= 0) {
        continue;
      }
      nodes[ni].depth = bfsQ[i].depth + 1;
      nodes[ni].parent = bfsQ[i].index;
      bfsQ.push(nodes[ni]);
    }
  }

  const sort = nodes.slice(1).sort((lhs, rhs) => {
    return rhs.depth - lhs.depth;
  });

  for (const n of sort) {
    if (!n.apple) {
      continue;
    }
    nodes[n.parent].apple = true;
    nodes[n.parent].need += n.need + 2;
  }

  return nodes[0].need;
};

console.log(minTime(7, [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], [false,false,true,false,true,true,false]));
