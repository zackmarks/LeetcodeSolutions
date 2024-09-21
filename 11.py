"""
11. Container With Most Water
https://leetcode.com/problems/container-with-most-water/
Skills: Two pointer, algorithm
"""


class Solution:
    def maxArea(self, height: List[int]) -> int:

        l = 0
        r = len(height)-1
        bigArea = 0

        while r > l:
            hei = min(height[l], height[r])
            wid = r-l
            curArea = hei * wid
            bigArea = max(bigArea, curArea)
            if height[l] > height[r]:
                r-=1
            else:
                l += 1
        return bigArea

