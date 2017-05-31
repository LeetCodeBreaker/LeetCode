class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
    
       let chars = Array(s.characters)
        
        let count = chars.count
        var map : [Character : Int] = [:]
        var ans = 0
        var i = 0
        
        for j in 0..<count{
            
            let c = chars[j]
            
            if let position = map[c] {
                 i = max(i,position + 1)
            }
            map[c] = j
            
            ans = max(ans, j-i+1)
        }
        
        return  ans;



    }
}
