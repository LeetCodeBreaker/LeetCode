//https://en.wikipedia.org/wiki/Cycle_detection
class Solution {
    func isHappy(_ n: Int) -> Bool {
        var slow = n
        var fast = n
        repeat {
            
            slow = sumOfSquareOfDigits(slow)
            fast = sumOfSquareOfDigits(fast)
            fast = sumOfSquareOfDigits(fast)
            if slow == 1 || fast == 1 {
                return true
            }
        
        }while slow != fast
    
        return false
    }
    
    func sumOfSquareOfDigits(_ n : Int) -> Int{
        
        var answer = 0
        var n = n
        while n != 0{
            let digit = n % 10
            answer += digit * digit
            n = n / 10
        }
        
        return answer
    }
}
