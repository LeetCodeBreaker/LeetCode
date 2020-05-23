/**
 * @param {string[][]} favoriteCompanies
 * @return {number[]}
 */
var peopleIndexes = function(favoriteCompanies) {
  for (const f of favoriteCompanies) {
    f.sort();
  }
  const sorted = favoriteCompanies.map((o, idx) => {
    return {o, idx};
  }).sort((lhs, rhs) => {
    return rhs.o.length - lhs.o.length;
  });

  const includes = (large, small) => {
    let si = 0;
    for (let li = 0; li < large.length; li++) {
      if (large[li] === small[si]) {
        si += 1;
      }
    }
    return si === small.length;
  };

  const arr = [];
  for (let i = 0; i < sorted.length; i++) {
    const {o, idx} = sorted[i];
    let has = false;
    for (let j = 0; j < i; j++) {
      const {o: oo} = sorted[j];
      has = has || includes(oo, o);
    }
    if (!has) {
      arr.push(idx);
    }
  }

  return arr.sort((lhs, rhs) => {
    return lhs - rhs;
  });
};

console.log(peopleIndexes([["leetcode","google","facebook"],["google","microsoft"],["google","facebook"],["google"],["amazon"]]));
console.log(peopleIndexes([["arrtztkotazhufrsfczr","knzgidixqgtnahamebxf","zibvccaoayyihidztflj"],["cffiqfviuwjowkppdajm","owqvnrhuzwqohquamvsz"],["knzgidixqgtnahamebxf","owqvnrhuzwqohquamvsz","qzeqyrgnbplsrgqnplnl"],["arrtztkotazhufrsfczr","cffiqfviuwjowkppdajm"],["arrtztkotazhufrsfczr","knzgidixqgtnahamebxf","owqvnrhuzwqohquamvsz","qzeqyrgnbplsrgqnplnl","zibvccaoayyihidztflj"]]));
