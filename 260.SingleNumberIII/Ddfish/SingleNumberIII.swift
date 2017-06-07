class Solution {
    func singleNumber(_ nums: [Int]) -> [Int] {
        
        var answer1 = 0
        var answer2 = 0
        var diff = 0
        for num in nums {
            diff ^= num
        }
        if diff == 0 { return [] }
        // 現在的diff = a ^ b
        // a & b 一定有1個以上的bit 不一樣
        // 找到某一個不一樣的bit
        diff &= -diff
        // 這裡用的是最小的bit
        // 把nums 分成有這個bit 和沒這個bit的
        // 再分別下去做 &= 
        // 就可以得到答案
        for num in nums {
            if num & diff == 0 {
                answer1 ^= num
            }else{
                answer2 ^= num
            }
        }
        return [answer1,answer2]
    }
}
