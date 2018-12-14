/**
 * @param {number[]} heights
 * @return {number}
 */
var largestRectangleArea = function(heights) {
    let max = 0;
    let record = heights.map(s => null);
    let sorted = heights.map((v, i) => {return {v, i}})
    sorted.sort((l, r) => {
        return (r.v - l.v) || (l.i - r.i);
    });

    sorted.forEach(o => {
        record[o.i] = {left: o.i, right: o.i};
        const leftIndex = record[o.i - 1] ? record[o.i - 1].left : o.i;
        const rightIndex = record[o.i + 1] ? record[o.i + 1].right : o.i;
        record[leftIndex].right = rightIndex;
        record[rightIndex].left = leftIndex;
        max = Math.max(max, (rightIndex - leftIndex + 1) * o.v);
    });
    return max;
};
