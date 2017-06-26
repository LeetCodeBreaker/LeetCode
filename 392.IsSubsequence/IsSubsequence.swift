class Solution {
    func isSubsequence(_ s: String, _ t: String) -> Bool {
        
        if s == "" {
            return true
        }
        
        var arrayS = Array(s.characters)
        var arrayT = Array(t.characters)
        
        var s = 0
        for char in arrayT {
            
            if arrayS[s] == char{
                if s == arrayS.count - 1 {
                    return true
                }
                s += 1
            }
        
        }
        
        
        return false
    }
}
