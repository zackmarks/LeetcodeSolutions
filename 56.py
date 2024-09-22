"""
56. Merge Intervals
https://leetcode.com/problems/merge-intervals/description/
Skills: Intervals, Algorithms, Sorting, Greedy
"""

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        def customSort(tups):
            return sorted(tups, key=lambda x: (x[0], -x[1]))

        intervals = customSort(intervals)
        ret = []
        for (s,e) in intervals:
            if len(ret) == 0:
                ret.append((s,e))
                continue
            (sr, er) = ret[-1]
            if(s <= er):
                newTup = (sr, max(e, er))
                ret[-1] = newTup
            else:
                ret.append((s,e))
        return ret

