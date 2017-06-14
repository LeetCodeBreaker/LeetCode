class Solution {
    func canCompleteCircuit(_ gas: [Int], _ cost: [Int]) -> Int {
        
        //我原本作法是計算每一段的revenue
        //然後從第i個站點出發去計算這段路程是否都>0
        //但是這樣就重複計算了每一個點的revenue( O(n^n))
        
        var total = 0
        var revenue = 0
        var start = 0
        for i in 0 ..< gas.count {
            total += gas[i] - cost[i]
            if revenue < 0 {
                //從start 到 i 盈餘為負的 不可能從start出發
                //改從i出發試看看
                revenue = gas[i] - cost[i]
                start = i
            } else { //從start出發到目前站位（i)都有盈餘
                revenue += gas[i] - cost[i]
            }
        }
        return total >= 0 ? start : -1
    }
}
