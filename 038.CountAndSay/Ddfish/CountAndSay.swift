class Solution {
    func countAndSay(_ n: Int) -> String {
        
        var answer = "1"
        
        for i in 1..<n {
            var tempString = ""
            var count = 1
            let chars = Array(answer.characters)
            var tempChar = chars[0]
            for j in 1..<chars.count{
                if chars[j] == tempChar{
                    count += 1
                }else{
                    tempString += "\(count)\(tempChar)"
                    tempChar = chars[j]
                    count = 1
                }
            }
            tempString += "\(count)\(tempChar)"
            answer = tempString

        }
        
        return answer
    }
}
