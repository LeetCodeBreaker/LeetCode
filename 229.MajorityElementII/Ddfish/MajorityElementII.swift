class Solution {
    func majorityElement(_ nums: [Int]) -> [Int] {
        
        if nums.count <= 1 {
            return nums
        }
        
        var canditate1 = 0
        var canditate2 = 0
        var count1 = 0
        var count2 = 0
        for num in nums{
            if canditate1 == num{
                count1 += 1
            }else if canditate2 == num{
                count2 += 1
            }else if count1 == 0{
                canditate1 = num
                count1 = 1
            }else if count2 == 0{
                canditate2 = num
                count2 = 1
            }else {
                count1 -= 1
                count2 -= 1
            }
        }

        var answer : [Int] = []
        count1 = 0
        count2 = 0
        for num in nums{
            if num == canditate1 {
                count1 += 1
            }else if num == canditate2{
                count2 += 1
            }
        }
        if count1 > nums.count / 3 {
            answer.append(canditate1)
        }
        if count2 > nums.count / 3 {
            answer.append(canditate2)
        }
        
        return answer
    }
}
