class Solution {
    func reverse(_ x: Int) -> Int {
        
        var xInt32 : Int32 = Int32(x)
        var answer : Int32 = 0
        
        while xInt32 != 0 {
            
            let result = Int32.multiplyWithOverflow(answer, Int32(10))
            let digit = xInt32 % 10
            xInt32 /= 10
            if(result.overflow){
                return 0
            }else{
                answer = result.0 + digit
            }
        }
        
        return Int(answer)

    }
}
