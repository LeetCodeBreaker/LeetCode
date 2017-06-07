class Solution {
    func isPalindrome(_ x: Int) -> Bool {
    
        if x < 0  { return false } 
        if x < 10 { return true }
        var temp = x 
        var y = 0
        while temp != 0 {
            
            y = y * 10 + temp % 10
            temp = temp / 10 
        }
        
        return x == y 
    }
}
