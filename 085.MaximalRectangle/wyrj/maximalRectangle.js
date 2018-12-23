/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalRectangle = function(matrix) {
    if (matrix.length === 0) return 0;
    
    const histogram = [];
    for (let r = 0; r < matrix.length; r++) {
        histogram[r] = [];
        for (let c = 0; c < matrix[r].length; c++) {
            histogram[r][c] = matrix[r][c] === '0' ? 0 : (r === 0 ? 1 : 1 + histogram[r - 1][c]);
        }
    }
    
    function findMaxFromHistogram(heights) {
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
    }

    return histogram.reduce((max, arr) => {
        return Math.max(max, findMaxFromHistogram(arr));
    }, 0);
};
