class Solution {
    func hammingDistance(_ x: Int, _ y: Int) -> Int {
    
        var x = x 
        var y = y
        var answer = 0
        
        while x != 0 || y != 0 {
    
            if x & 1 != y & 1 {
                answer += 1
            }
            x = x >> 1
            y = y >> 1
        }
        
        return answer
    }
}
