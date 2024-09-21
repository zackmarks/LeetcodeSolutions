"""
539. Minimum Time Difference
https://leetcode.com/problems/minimum-time-difference/
Skills: Algorithms
"""

class Solution:
    def compareTimes(self, hour1: int, min1: int, hour2: int, min2: int) -> int:
        time1 = hour1 * 60 + min1
        time2 = hour2 * 60 + min2
        diff = time2 - time1
        return min(diff, 24*60 - diff)

    def stringToTime(self, t: str):
        m = int(t[-2:])
        h = int(t[0:-3])
        return h,m

    def calcDiff(self, t1: str, t2: str) -> int:
        t11, t12 = self.stringToTime(t1)
        t21, t22 = self.stringToTime(t2)
        return self.compareTimes(t11, t12, t21, t22)

    def findMinDifference(self, timePoints: List[str]) -> int:
        timePoints.sort()

        loDiff = self.calcDiff(timePoints[0], timePoints[-1]) #NameError: name 'calcDiff' is not defined. Did you mean: 'curDiff'?

        for i in range (len(timePoints) - 1):
            curDiff = self.calcDiff(timePoints[i], timePoints[i+1])
            loDiff = min(loDiff, curDiff)

        return loDiff

