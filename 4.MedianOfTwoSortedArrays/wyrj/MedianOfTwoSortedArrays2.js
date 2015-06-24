/* 304ms */
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    var findMedian = function(arr1, start1, arr2, start2, target){
        if (start1 === arr1.length) {
            return [start1, start2 + target];
        } else if (start2 === arr2.length) {
            return [start1 + target, start2];
        }
        if (1 === target) {
            if (arr1[start1] >= arr2[start2]) {
                return [start1, start2 + 1];
            } else {
                return [start1 + 1, start2];
            }
        }
        var half = Math.floor(target/2);
        var n1 = (half + start1 -1 >= arr1.length) ? arr1.length - 1 : half + start1 - 1;
        var n2 = (half + start2 -1 >= arr2.length) ? arr2.length - 1 : half + start2 - 1;
        if (arr1[n1] >= arr2[n2]) {
            return findMedian(arr1, start1, arr2, n2+1, target-(n2-start2+1));
        } else {
            return findMedian(arr1, n1+1, arr2, start2, target-(n1-start1+1));
        }
    };
    var maxMin = function(a, b, maxFlag) {
        if ('undefined' === typeof a) {
            return b;
        } else if ('undefined' === typeof b) {
            return a;
        } else if (true === maxFlag){
            return Math.max(a, b);
        } else {
            return Math.min(a, b);
        }
    };
    var next = findMedian(nums1, 0, nums2, 0, Math.floor((nums1.length + nums2.length)/2));
    if (0 === (nums1.length + nums2.length) % 2) {
        return (maxMin(nums1[next[0]], nums2[next[1]]) + maxMin(nums1[next[0]-1], nums2[next[1]-1], true))/2;
    } else {
        return maxMin(nums1[next[0]], nums2[next[1]]);
    }
};