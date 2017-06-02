class Solution {
    
   func myAtoi(_ str: String) -> Int {
        
        var chars = Array(str.characters)
        var isNegative = false;
        var result : Int32 = 0
        
        while(chars.first == " "){
            chars.removeFirst()
        }
        
        if(chars.first == "+"){
            chars.removeFirst()
        }else if(chars.first == "-"){
            chars.removeFirst()
            isNegative = true;
        }
        
        for i in 0 ..< chars.count {
            
            if let digit = Int32("\(chars[i])"){
                
                if Int32.multiplyWithOverflow(result, 10).overflow{
                    return Int(isNegative ? Int32.min : Int32.max)
                }else if Int32.addWithOverflow(result * 10, digit).overflow {
                    return Int(isNegative ? Int32.min : Int32.max)
                }else{
                    result = result * 10 + digit
                }
                
                
            }else{
                break
            }
            
            
        }
        
        return Int(result * (isNegative ? -1 : 1))
    }
    
}

