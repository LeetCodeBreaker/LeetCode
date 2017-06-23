class Solution {
    func repeatedSubstringPattern(_ s: String) -> Bool {
        
        let chars = Array(s.characters)
        if chars.count == 1 { return false }
        for i in (1...chars.count/2).reversed() {
            if chars.count % i == 0 {
                var str = ""
                let subStr = String(chars[0..<i])
                for j in 0..<(chars.count/i){
                    str.append(subStr)
                }
                if s == str {
                    return true
                }
            }
        }
        
        return false
    }
}

