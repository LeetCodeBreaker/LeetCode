
import Foundation
class Solution {
    func findMinDifference(_ timePoints: [String]) -> Int {
        var times : [Int] = []
        for timePoint in timePoints{
            let strs  = timePoint.components(separatedBy: ":")
            let time = Int(strs[0])! * 60 + Int(strs[1])!
            times.append(time)
        }
        times.sort()
        var minDiff = 1441
        for i in 0..<times.count-1{
            let diff = times[i+1] - times[i]
            if diff < minDiff{
                minDiff = diff
            }
        }
        let diff = times[0] - times.last! + 1440
        if diff < minDiff{
            minDiff = diff
        }
        return minDiff
    }
   
}





