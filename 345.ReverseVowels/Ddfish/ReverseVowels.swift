//O(n)
class Solution {
    
    func reverseVowels(_ s: String) -> String {
        
        let vowels : [Character] = ["a","e","i","o","u","A","E","I","O","U"]
        var charArray = Array(s.characters)
        var start = 0
        var end = charArray.count-1
 
	      
        while start < end {
            while start < end && !vowels.contains(charArray[start]){
                start += 1
            }
            while start < end && !vowels.contains(charArray[end]){
                end -= 1
            }

            if(start < end){
                let temp = charArray[start]
                charArray[start] = charArray[end]
                charArray[end] = temp
                start += 1
                end -= 1
            }else{
                return String(charArray)
            }
        }
        return String(charArray)
    }

}
