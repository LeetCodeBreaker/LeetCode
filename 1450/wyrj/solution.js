/**
 * @param {number[]} startTime
 * @param {number[]} endTime
 * @param {number} queryTime
 * @return {number}
 */
var busyStudent = function(startTime, endTime, queryTime) {
  return startTime.filter((s, idx) => {
    return s <= queryTime && queryTime <= endTime[idx];
  }).length;
};

console.log(busyStudent([1,2,3],[3,2,7],4));
