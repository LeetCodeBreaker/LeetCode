/*
	跟046解答差不多，不過多一個紀錄重複的動作
	效率比較差一點，我看無效率好的方法QQ

*/
class Solution {
    func permuteUnique(_ nums: [Int]) -> [[Int]] {
        if nums.count <= 1 { return [nums]}
        if nums.count == 2 {
            if nums[0] == nums[1] {
                return [nums]
            }else{
                return [nums,nums.reversed()]
            }
        }
        var answer : [[Int]] = []
        var used : [Int] = []
        for i in 0..<nums.count{
            
            if used.contains(nums[i]){
                continue
            }
            var nums = nums
            let firstElement = nums.remove(at: i)
            used.append(firstElement)
            for child in permuteUnique(nums){
                var child = child
                child.insert(firstElement, at: 0)
                answer.append(child)
            }
            
        }
        
        return answer
    }
}
