import Foundation

class Solution {
    func isIsomorphic(_ s: String, _ t: String) -> Bool {
        
        if s == t { return true }
        
        let sChar = Array(s.characters)
        let tChar = Array(t.characters)
        var dict : [Character : Character] = [:]
       
        
        for i in 0..<sChar.count {
            
            let s = sChar[i]
            let t = tChar[i]
            
            if let value = dict[s]{ // 有值 比較是否正確
                if value != t { return false }
            }else{ //沒值要先確定value內沒有
                if dict.values.contains(t) {
                    return false
                }
                dict[s] = t
            }
        }
        
        
        return true
    }
}




