class Solution {
    func majorityElement(_ nums: [Int]) -> Int {
        var canditate = nums[0]
        var count = 1
        for i in 1..<nums.count{
            if count == 0 {
                canditate = nums[i]
                count = 1
            }else if nums[i] == canditate{
                count += 1
            }else{
                count -= 1
            }
        }
        
        return canditate
    }
}
