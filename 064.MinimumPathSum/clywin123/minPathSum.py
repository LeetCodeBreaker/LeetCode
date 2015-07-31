class Solution:
    # @param {integer[][]} grid
    # @return {integer}
    def minPathSum(self, grid):    
        n = len(grid[0])
        m = len(grid)
        mappath = [[0 for i in range(n)] for j in range(m)]
        mappath[0][0] = grid[0][0]
        for i in range(1,n):
            mappath[0][i] = mappath[0][i-1]+grid[0][i]
        for i in range(1,m):
            mappath[i][0] = mappath[i-1][0]+grid[i][0]
        for i in range(1,m):
            for j in range(1,n):
                mappath[i][j]=min(mappath[i-1][j]+grid[i][j],mappath[i][j-1]+grid[i][j])
        return mappath[m-1][n-1]
        
