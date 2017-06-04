class Solution {
    func plusOne(_ digits: [Int]) -> [Int] {
        var digits = digits
        for i in (0..<digits.count).reversed() {
            
            if(digits[i] + 1 < 10){
                digits[i] += 1 
                return digits
            }
            // >10 
            digits[i] = 0 
        }
        // 多加一個0
        digits.insert(1, at: 0)
        return digits
    }
}
