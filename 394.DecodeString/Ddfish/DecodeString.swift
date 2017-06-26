class Solution {
    func decodeString(_ s: String) -> String {
        
        var charsArray = Array(s.characters)
        var stackArray : [String] = []
        
        for char in charsArray{
            
            if char == "["{
                //先把前面的數字湊起來
                var tempStr = ""
                while true {
                    
                    if let last = stackArray.popLast(){
                        if last >= "0" && last <= "9" {
                            tempStr = last + tempStr
                        }else{
                            stackArray.append(last)
                            break
                        }
                    }else{
                        break
                    }
                }
                stackArray.append(tempStr)
                stackArray.append("[")
                
            }else if char == "]"{
                //把[]內的拼起來 然後加回去
                var tempStr = ""
                while true{
                    
                    let last =  stackArray.popLast()!
                    if last != "["{
                        tempStr = last + tempStr
                    }else{
                        break
                    }
                }
                let number = Int(stackArray.popLast()!)!
                for i in 0..<number {
                    stackArray.append(tempStr)
                }
            }else{ //除了[]以外的 直接加進去
                
                stackArray.append("\(char)")
            }
        }
        var answer = ""
        
        for str in stackArray{
            answer += str
        }
        
        return answer
    }
}
