class Solution {
    func summaryRanges(_ nums: [Int]) -> [String] {
        
        if(nums.count == 0){
            return []
        }
        
        var result : [String]  = []
        var start = nums[0]
        var end = nums[0]
        
        for i in 1..<nums.count {
            
            if nums[i] != nums[i-1] + 1{
                result.append(range(start, end))
                start = nums[i]
            }
            end = nums[i]
        
        }
        result.append(range(start, end))
        return result
    }
    
    private func range(_ start : Int , _ end : Int) -> String{
        if( start == end) {
            return "\(start)"
        }
        return "\(start)->\(end)"
    }
}
