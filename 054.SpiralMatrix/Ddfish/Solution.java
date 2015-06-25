public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> answer = new ArrayList<>();
        int m = 0 ;
        int n = 0 ;
        try{
            m = matrix.length;
            n = matrix[0].length;
        }catch(ArrayIndexOutOfBoundsException e){
            return answer;
        }
        boolean[][] b = new boolean[m][n];
        int stepY = 1;
        int stepX = 0;
        int x = 0 ;
        int y = 0 ;
      
        for(int i = 0 ; i < m*n ; i++ ){
            answer.add(matrix[x][y]);
            b[x][y] = true;
            if(x+stepX >= m || y+stepY >= n || x+stepX < 0 || y+stepY < 0 || b[x+stepX][y+stepY] == true){
                if(stepY != 0){
                    stepX = stepY;
                    stepY = 0;
                }else if(stepX != 0){
                    stepY = stepX * (-1);
                    stepX = 0;
                }
            }
            x += stepX;
            y += stepY;
        }
        return answer;
        
    }
}
