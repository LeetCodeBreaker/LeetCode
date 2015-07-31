class Solution:
    # @param {integer[]} height
    # @return {integer}
    def maxArea(self, height):
        left = 0
        right = len(height)-1
        water = 0
        while(left<=right):
            wall = min(height[left],height[right])
            if(wall*(right-left)>water):
                water = (right-left)*wall
            if(height[left]<=height[right]):
                left += 1
            else:
                right -=1
        return water
