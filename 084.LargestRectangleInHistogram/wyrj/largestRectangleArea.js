/**
 * @param {number[]} heights
 * @return {number}
 */
var largestRectangleArea = function(heights) {
    const stack = [];
    let popNumber = 0;
    let max = 0;
    
    for (let i = 0; i < heights.length; i++) {
        while (stack.length > 0 && heights[i] < stack[stack.length - 1].v) {
            const record = stack.pop();
            popNumber += record.p;
            max = Math.max(max, record.v * popNumber);
        }
        stack.push({v: heights[i], p: popNumber + 1});
        popNumber = 0;
    }
    while (stack.length > 0) {
        const record = stack.pop();
        popNumber += record.p;
        max = Math.max(max, record.v * popNumber);
    }
    return max;
};
