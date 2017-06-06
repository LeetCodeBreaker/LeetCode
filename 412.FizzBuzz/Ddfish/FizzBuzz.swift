class Solution {
    func fizzBuzz(_ n: Int) -> [String] {
       
        var result :[String] = []
        for i in 1...n {
            var str = ""
            if(i % 3 == 0){
                str += "Fizz"
            }
            if(i % 5 == 0){
                str += "Buzz"
            }
            if(str == ""){
                str = "\(i)"
            }
            result.append(str)
        }
        return result;
    }
}

