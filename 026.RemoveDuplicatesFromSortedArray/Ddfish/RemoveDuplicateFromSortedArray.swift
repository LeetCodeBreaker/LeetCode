/*
 
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 
 Do not allocate extra space for another array, you must do this in place with constant memory.
 
 For example,
 Given input array nums = [1,1,2],
 
 Your function should return length = 2,
 with nums = [1,2].
 It doesn't matter what you leave beyond the new length.
 
 */
/*
 Ans.
    原本的想法是把重複的element移除
    但是遇到Memory Limit Exceeded 的case 
    仔細看題目發現 array後面的值可以忽略不看
    因此改成用取代值的方法
 */


class Solution {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        
        if(nums.count <= 1) { return nums.count }
        var i = 1 // 把前面重複的蓋掉的指標
        var j = 1
        while j < nums.count {
            
            if nums[j] != nums[i - 1] {
                nums[i] = nums[j]
                i += 1
            }
            j += 1
        }
        return i
        
    }
}

