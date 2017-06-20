class Solution {
    func arrayPairSum(_ nums: [Int]) -> Int {
        
        var nums = nums.sorted()
        let count = nums.count
        var answer = 0
        for i in 0..<count/2 {
            answer += nums[i*2]
        }
        return answer
    }
}
