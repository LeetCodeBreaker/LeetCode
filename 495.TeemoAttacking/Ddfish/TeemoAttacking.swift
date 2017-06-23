class Solution {
    func findPoisonedDuration(_ timeSeries: [Int], _ duration: Int) -> Int {
        
        if timeSeries.count == 0 {
            return 0
        }
        var answer = 0
        var poisonStartTime = 0
        var poisonEndTime = 0
        for time in timeSeries{
            if time >= poisonEndTime{
                answer += poisonEndTime - poisonStartTime
                poisonStartTime = time
            }
            poisonEndTime = time + duration
        }
        answer += poisonEndTime - poisonStartTime
        return answer
    }
}
