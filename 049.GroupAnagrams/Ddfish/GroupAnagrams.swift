class Solution {
    func groupAnagrams(_ strs: [String]) -> [[String]] {
        
        var dicts : [ String : [String] ] = [:]
        for str in strs {
            let key  = String(str.characters.sorted())
            var values = dicts[key] ?? []
            values.append(str)
            dicts[key] = values
        }
        return Array(dicts.values)
    }
}
