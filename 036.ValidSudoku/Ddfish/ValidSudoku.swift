class Solution {
    func isValidSudoku(_ board: [[Character]]) -> Bool {
        
        var s = Set("123456789".characters)
        var rowSet : [Set] = [Set]( repeating: s, count: 9 )
        var columnSet : [Set] = [Set]( repeating: s, count: 9 )
        var squareSet : [Set] = [Set]( repeating: s, count: 9 )
        
        for i in 0..<9{
            for j in 0..<9{
                
                let char = board[i][j]
                if(char == "."){
                    continue
                }

                if(rowSet[i].contains(char)
                    && columnSet[j].contains(char)
                    && squareSet[i/3*3+j/3].contains(char)){
                    
                    rowSet[i].remove(char)
                    columnSet[j].remove(char)
                    squareSet[i/3*3+j/3].remove(char)
                }else{

                    return false
                }
               
                
            }
        }
        
        return true
    }
}
