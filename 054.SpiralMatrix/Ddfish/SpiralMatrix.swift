class Solution {
    static func spiralOrder(_ matrix: [[Int]]) -> [Int] {
        
        
        if(matrix.count == 0){
            return []
        }
        
        var answer : [Int] = []
        var rowStart = 0
        var rowEnd = matrix.count
       
        var columnStart = 0
        var columnEnd = matrix[0].count
        
        var step = 0
        while(rowStart < rowEnd && columnStart < columnEnd){
            
            switch step % 4 {
            case 0:  // right
                for j in columnStart..<columnEnd {
                    answer.append(matrix[rowStart][j])
                }
                rowStart += 1
            case 1: // down
                for i in rowStart..<rowEnd {
                    answer.append(matrix[i][columnEnd-1])
                }
                columnEnd -= 1
            case 2: // left
                for j in (columnStart..<columnEnd).reversed() {
                    answer.append(matrix[rowEnd-1][j])
                }
                rowEnd -= 1
            case 3: //up
                for i in (rowStart..<rowEnd).reversed(){
                    answer.append(matrix[i][columnStart])
                }
                columnStart += 1
            default:
                break;
            }
            step+=1
           
            
        }
        
        return answer
    }
}

