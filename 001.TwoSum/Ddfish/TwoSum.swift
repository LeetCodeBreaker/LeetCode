class Solution {
    func twoSum(nums: [Int], _ target: Int) -> [Int] {
        var dic : [Int : Int] = [:]
        for(var i = 0 ; i < nums.count ; i+=1){
            if let answer = dic[nums[i]]{
                return [answer,i]
            }
            dic[target-nums[i]] = i
        }
        return []
    }
}
