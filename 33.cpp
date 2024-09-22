"""
33. Search in Rotated Sorted Array
https://leetcode.com/problems/search-in-rotated-sorted-array/description/
Skills: Binary Search, Algorithms
"""

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums)-1

        # search for start of sorted array
        while l < r:
            mid = (l+r)//2
            if nums[mid] > nums[r]:
                l = mid+1
            else:
                r = mid
        
        #l is index of lowest element in array
        if target < nums[l]:
            return -1
        
        l2 = 0
        r2 = len(nums)-1
        if target < nums[0]:
            l2 = l
        else:
            if l != 0:
                r2 = l-1

        while l2 < r2:
            mid = (l2+r2) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                r2 = mid
            else:
                l2 = mid+1
        if nums[l2] == target:
            return l2
        return -1

