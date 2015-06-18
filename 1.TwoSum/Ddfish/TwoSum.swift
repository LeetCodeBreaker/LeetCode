public class TwoSum{
    static func  twoSum(nums : [Int] , target :Int) ->[Int]{
        
        for (var i = 0 ; i < nums.count - 1 ;i++){
            for(var j = i+1 ; j < nums.count ;j++){
                if(nums[i] + nums[j] == target){
                    return [nums[i],nums[j]]
                }
            }
        }
        return []
    }

}
