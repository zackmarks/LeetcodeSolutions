"""
74. Search a 2D Matrix
https://leetcode.com/problems/search-a-2d-matrix/description/
Skills: Binary Search
"""

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        lo = 0
        hi = len(matrix) - 1
        r = len(matrix[0]) - 1


        while lo < hi:
            mid = (lo + hi) // 2
            if matrix[mid][r] == target:
                return True
            elif matrix[mid][r] < target:
                lo = mid+1
            else:
                hi = mid
        
        # in row lo

        l = 0
        r = len(matrix[0]) - 1

        while l < r:
            mid = (l+r) // 2
            if matrix[lo][mid] == target:
                return True
            elif matrix[lo][mid] < target:
                l = mid+1
            else:
                r = mid - 1
        
        return matrix[lo][l] == target

