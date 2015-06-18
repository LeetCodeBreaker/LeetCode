class Solution:
# @param {integer[]} nums
# @param {integer} target
# @return {integer[]}
def twoSum(self, nums, target):
    record = dict()
    totalNum = len(nums)
    idx = 0
    for num in nums:
        if num in record:
            return [record[num] + 1, idx + 1]
        else:
            record[target - num] = idx
        idx += 1
