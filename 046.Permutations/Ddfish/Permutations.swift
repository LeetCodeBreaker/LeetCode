class Solution {
    func permute(_ nums: [Int]) -> [[Int]] {
        
        if nums.count <= 1 { return [nums] }
        if nums.count == 2 { return [nums,nums.reversed()]}
        
        var answer : [[Int]] = []
        
        for i in 0..<nums.count {
            
            //取一個值出來
            let firstElement = nums[i]
            var nums = nums
            nums.remove(at: i)
            
            //剩下的繼續做 permute
            let childs = permute(nums)
        
            //把原本取的值放在Array第一個
            for child in childs {
                var child = child
                child.insert(firstElement, at: 0)
                answer.append(child)
            }
            
        }
        
        return answer
    }
}
