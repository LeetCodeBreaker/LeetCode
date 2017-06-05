class Solution {
    func compareVersion(_ version1: String, _ version2: String) -> Int {
        
        if (version1 == version2) {
            return 0
        }
        var v1 = version1.components(separatedBy: ".")
        var v2 = version2.components(separatedBy: ".")
        var diff = v1.count - v2.count
        while diff != 0 {
            if(diff > 0){
                v2.append("0")
                diff -= 1
            }else{
                v1.append("0")
                diff += 1
            }
        }
        
        for i in 0..<v1.count{
            guard let x = Int(v1[i]) else{
                return -1
            }
            guard let y = Int(v2[i]) else{
                return 1
            }
            if (x != y){
                return x > y ? 1 : -1
            }
        }
        
        return 0
    }
}
