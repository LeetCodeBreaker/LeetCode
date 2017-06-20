
class Solution {
    func threeSumClosest(_ nums: [Int], _ target: Int) -> Int {
        
        var answer = 0
        var nums = nums.sorted()
        var diff = Int.max
        
        for i in 0..<nums.count - 2 {
            var j = i + 1
            var k = nums.count - 1
            while j < k {
                let tempDiff = nums[i] + nums[j] + nums[k] - target
                if abs(tempDiff) < diff {
                    
                    if tempDiff == 0 {
                        return target
                    }
                    diff = abs(tempDiff)
                    answer = tempDiff + target
                }
                if tempDiff > 0 {
                    k -= 1
                }else if tempDiff < 0{
                    j += 1
                }
            }
        
        }
        
        
        return answer
    }
}
