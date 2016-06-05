/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    var queue = [], last = null;
    var i, result = 0, fillHeight = 0;
    for (i = 0; i < height.length; i++) {
        h = height[i];
        while(true) {
            if (0 === queue.length) {
                queue.push({index: i, height: h});
                fillHeight = 0;
                break;
            }
            last = queue[queue.length - 1];
            result += ((Math.min(h, last.height) - fillHeight) * (i - last.index - 1));
            fillHeight = last.height;
            if (last.height > h) {
                queue.push({index: i, height: h});
                break;
            } else {
                queue.pop();
            }
        }
    }
    return result;
};