/**
 * Definition for an interval.
 * function Interval(start, end) {
 *     this.start = start;
 *     this.end = end;
 * }
 */
/**
 * @param {Interval[]} intervals
 * @param {Interval} newInterval
 * @return {Interval[]}
 */
var insert = function(intervals, newInterval) {
    if (0 === intervals.length) {
        return [newInterval];
    }
    if (intervals[0].start > newInterval.end) {
        intervals.unshift(newInterval);
        return intervals;
    }
    if (intervals[intervals.length - 1].end < newInterval.start) {
        intervals.push(newInterval);
        return intervals;
    }
    var left = 0, right = intervals.length - 1;
    while (intervals[left].end < newInterval.start) {
        left += 1;
    }
    while (intervals[right].start > newInterval.end) {
        right -= 1;
    }
    newInterval.start = Math.min(intervals[left].start, newInterval.start);
    newInterval.end = Math.max(intervals[right].end, newInterval.end);
    intervals.splice(left, right - left + 1, newInterval);
    return intervals;
};