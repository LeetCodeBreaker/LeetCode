class Solution {
    func findMaxLength(_ nums: [Int]) -> Int {
        //https://discuss.leetcode.com/topic/80056/python-o-n-solution-with-visual-explanation
        var count = 0
        var answer = 0
        var table : [Int:Int] = [0:0] //紀錄首次出現的position
        
        for i in 0..<nums.count {
            
            count += nums[i] == 0 ? -1 : 1
            if let firstPosition = table[count]{
                answer = max(answer,i+1-firstPosition)
            }else{
                table[count] = i+1
            }
        }
        
        return answer
    }
}
