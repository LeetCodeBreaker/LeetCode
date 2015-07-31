class Solution:
    def solveNQueens(self, n):
        ans=[0 for i in range(n)] 
        row = [0 for i in range(n)]
        dig = [0 for i in range(2*n)]
        indig = [0 for i in range(2*n)]
        chessboard = []
        return self.queens(n,0,ans,row,dig,indig,chessboard)
    def totalNQueens(self, n):
        return len(self.solveNQueens(n))
    def queens(self,n,col,ans,row,dig,indig,chessboard):
        for i in range(n):
            if(col == n):
                tmplist = []
                tmpstr = ""
                for p in range(n):
                    for q in range(n):
                        if(ans[p]!=q):
                            tmpstr += "."
                        else:
                            tmpstr += "Q"
                    tmplist.append(tmpstr)
                    tmpstr = ""
                chessboard.append(tmplist)
                return
            if(row[i]==0 and dig[i-col+n-1]==0 and indig[i+col]==0):
                row[i]=1
                dig[i-col+n-1]=1
                indig[i+col]=1
                ans[col]=i
                self.queens(n,col+1,ans,row,dig,indig,chessboard)        
                row[i]=0
                dig[i-col+n-1]=0
                indig[i+col]=0
                ans[col]=0
        return chessboard
