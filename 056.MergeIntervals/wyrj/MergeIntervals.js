/**
 * Definition for an interval.
 * function Interval(start, end) {
 *     this.start = start;
 *     this.end = end;
 * }
 */
/**
 * @param {Interval[]} intervals
 * @return {Interval[]}
 */
var merge = function(intervals) {
    var result = [], i, interval;
    intervals.sort(function(lhs, rhs) {
        return (lhs.start - rhs.start) || (lhs.end - rhs.end);
    });
    for (i = 0; i < intervals.length; i++) {
        if (!interval || interval.end < intervals[i].start) {
            interval = new Interval(intervals[i].start, intervals[i].end);
            result.push(interval);
        } else {
            interval.end = Math.max(interval.end, intervals[i].end);
        }
    }
    return result;
};