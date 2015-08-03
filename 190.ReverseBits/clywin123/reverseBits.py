class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        rev = [(n>>i)&1 for i in range(32)]
        string1 = ''.join(str(x) for x in rev)
        return int(string1,2)
        
