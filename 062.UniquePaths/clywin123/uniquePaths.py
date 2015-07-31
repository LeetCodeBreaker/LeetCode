class Solution:
    # @param {integer} m
    # @param {integer} n
    # @return {integer}
    def uniquePaths(self, m, n):
        mappath = [[0 for i in range(n)] for j in range(m)]
        for i in range(n):
            mappath[0][i] = 1
        for i in range(m):
            mappath[i][0] = 1
        for i in range(1,m):
            for j in range(1,n):
                mappath[i][j]=mappath[i-1][j]+mappath[i][j-1]
        return mappath[m-1][n-1]
