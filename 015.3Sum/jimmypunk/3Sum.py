class Solution:
    # @param {integer[]} nums
    # @return {integer[][]}

    def threeSum(self, nums):
        nums.sort()

        N = len(nums)
        ans = []
        for i in xrange(N - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            start_idx = i + 1
            end_idx = N - 1

            while(start_idx < end_idx):
                sum = nums[i] + nums[start_idx] + nums[end_idx]

                if sum > 0:
                    end_idx -= 1
                elif sum < 0:
                    start_idx += 1
                else:
                    ans.append([nums[i], nums[start_idx], nums[end_idx]])
                    start_idx += 1
                    end_idx -= 1

                    while(start_idx < end_idx) and nums[start_idx] == nums[start_idx - 1]:
                        start_idx += 1
                    while(start_idx < end_idx) and nums[end_idx] == nums[end_idx + 1]:
                        end_idx -= 1

        return ans
