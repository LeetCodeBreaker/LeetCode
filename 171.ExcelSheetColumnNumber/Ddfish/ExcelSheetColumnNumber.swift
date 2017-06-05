class Solution {
    func titleToNumber(_ s: String) -> Int {
        var answer = 0
        for i in s.unicodeScalars{
            answer *= 26
            answer += i.hashValue - 64
        }
        return answer

    }
}
