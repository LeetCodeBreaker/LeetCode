/**
 * @param {number} n
 * @return {number}
 */
var numTrees = function(n) {
    const map = [1, 1];
    const r = (k) => {
        if (map[k]) return map[k];
        
        map[k] = 0;
        for (let i = 0; i < k; i++) {
            map[k] += r(i) * r(k - i - 1);
        }
        return map[k];
    }
    return r(n);
};
