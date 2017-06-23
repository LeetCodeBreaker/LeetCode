import Foundation
class Solution {

    func complexNumberMultiply(_ a: String, _ b: String) -> String {
        
        let a = complexStringToNumber(a)
        let b = complexStringToNumber(b)

        let answerReal = a.real * b.real - a.imagine * b.imagine
        let answerImagine = a.real * b.imagine + a.imagine * b.real
        
        return "\(answerReal)+\(answerImagine)i"
    }
    
    func complexStringToNumber(_ str : String) -> (real : Int, imagine : Int){
        let split = str.replacingOccurrences(of: "i", with: "").components(separatedBy: "+")
        return (Int(split[0])!,Int(split[1])!)
    }
}
