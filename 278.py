"""
278. First Bad Version
https://leetcode.com/problems/first-bad-version/description/
Skills: Binary Search, Algorithms
"""

# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        l = 1
        r = n

        while l < r:
            mid = (l+r) // 2
            if isBadVersion(mid):
                r = mid
            else:
                l = mid + 1
        return l

