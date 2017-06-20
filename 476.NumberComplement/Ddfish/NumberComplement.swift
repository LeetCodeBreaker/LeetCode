class Solution {
    func findComplement(_ num: Int) -> Int {
        var answer = 0
        var num = num
        var digit = 0
        while num != 0 {
            
            if num & 1 == 0{
                answer += 1 << digit
            }
            num = num >> 1
            digit += 1
           
        }
        return answer
    }
}
