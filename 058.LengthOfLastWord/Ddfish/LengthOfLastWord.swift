class Solution {
    func lengthOfLastWord(_ s: String) -> Int {
    
        let subStrArray = s.components(separatedBy: " ")
        for str in subStrArray.reversed() {
            if(str != ""){
                return str.characters.count
            }
        }
        return 0
    }
}
