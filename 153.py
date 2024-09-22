"""
153. Find Minimum in Rotated Sorted Array
Suppose an array of len
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Skills: Binary Search, Algorithms
"""

class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        while l < r:
            mid = (l+r) // 2
            if nums[mid] > nums[r]:
                l = mid + 1
            elif nums[mid] < nums[r]:
                r = mid 
            else: #nums[mid] == nums[r]
                return nums[l]
        return nums[l]

