class Solution {
    func isValid(_ s: String) -> Bool {
        
        let chars = Array(s.characters)
        var stack = Stack(stack: [])
        
        for char in chars {
            
            switch char {
            case "(": fallthrough
            case "[": fallthrough
            case "{":
                stack.push(char)
            case ")":
                if stack.pop() !=  "("{
                    return false
                }
            case "]":
                if stack.pop() !=  "["{
                    return false
                }
            case "}":
                if stack.pop() !=  "{"{
                    return false
                }
            default:
                continue
            }
        }
        
        return stack.isEmpty()
    }
}

struct Stack {
    
    fileprivate var stack : [Character] = []
    
    mutating func push(_ char : Character) {
        stack.append(char)
    }
    
    mutating func pop() -> Character? {
        if stack.isEmpty {
            return nil
        }
        return stack.removeLast()
    }
    
    func isEmpty() -> Bool {
        return stack.isEmpty
    }
}
