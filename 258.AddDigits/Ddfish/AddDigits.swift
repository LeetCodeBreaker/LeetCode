// 用手把答案一個一個寫下來就知道
// 答案有簡單的規律!!!
class Solution {
    func addDigits(_ num: Int) -> Int {
        if num == 0 { return 0 }
        let mode9 = num % 9 
        return mode9 == 0 ? 9 : mode9
    }
}
