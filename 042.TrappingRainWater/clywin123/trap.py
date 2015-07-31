class Solution:
    # @param {integer[]} height
    # @return {integer}
    answer = 0
    def findmaxindex(self,height):
        maxnum = 0
        index = 0
        for i in range(len(height)-1,-1,-1):
            if(height[i]>maxnum):
                maxnum = height[i]
                index = i
        return index
    def trap(self, height):
        if(len(height)<=2):
            return 0
        maxwall = self.findmaxindex(height)
        if(maxwall+1<len(height)):
            right = maxwall+self.findmaxindex(height[maxwall+1:len(height)])+1
            if(right-maxwall>=2):
                for i in range(maxwall+1,right):
                    self.answer+= (height[right]-height[i])
            self.trap(height[right:len(height)])
        if(maxwall-1>=0):
            left = self.findmaxindex(height[0:maxwall])
            if(maxwall-left>=2):
                for i in range(left+1,maxwall):
                    self.answer+= (height[left]-height[i])
            self.trap(height[0:left+1])
        return self.answer
