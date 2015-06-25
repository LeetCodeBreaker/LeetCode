/* 256ms */
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    var isEven = (0 === (nums1.length + nums2.length)%2) ? true : false;
    var findMedian = function(arr){
        var len = arr.length;
        if (isEven) {
            return (arr[len/2] + arr[len/2-1]) / 2;
        } else {
            return arr[Math.floor(len/2)];
        }
    }
    var bSearch = function(arr, t) {
        var i = 0, j = arr.length - 1;
        if (arr[i] > t) {
            return 0;
        } else if (arr[j] < t) {
            return arr.length;
        }
        while(i <= j) {
            var n = Math.floor((i+j)/2);
            if (arr[n] >= t && (arr[n-1] < t || 0 === n)) {
                return n;
            }
            if (arr[n] >= t) {
                j = n - 1;
            } else {
                i = n + 1;
            }
        }
    };
    var max = function(a, b) {
        if ('undefined' === typeof a) {
            return b;
        } else if ('undefined' === typeof b) {
            return a;
        } else {
            return Math.max(a, b);
        }
    };
    if (0 === nums1.length) {
        return findMedian(nums2);
    } else if (0 === nums2.length) {
        return findMedian(nums1);
    }
    var target = Math.floor((nums1.length + nums2.length) / 2);
    var i = 0, j = nums1.length - 1, m = 0, n = 0;
    while(i <= j) {
        n = Math.floor((i+j)/2);
        m = bSearch(nums2, nums1[n]);
        if (target === (m + n)){
            if (isEven) {
                return (nums1[n] + max(nums1[n-1], nums2[m-1])) / 2;
            } else {
                return nums1[n];
            }
        } else if (target > (m + n)) {
            i = n + 1;
        } else {
            j = n - 1;
        }
    }
    if (target > (m+n)) {
        m = target - n - 1;
        n = n + 1;
    } else {
        m = target - n;
    }
    if (isEven) {
        return (nums2[m] + max(nums1[n-1], nums2[m-1])) / 2;
    } else {
        return nums2[m];
    }
};