"""
200. Number of Islands
https://leetcode.com/problems/number-of-islands/description/
Skills: Graphs, Search, DFS
"""


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        islandCount = 0

        q = deque()
        dirChange = [(-1,0), (1,0), (0,-1), (0,1)]

        y = len(grid)
        x = len(grid[0])
        if x == 0 or y == 0:
            return 0

        def isLegalLoc(curY, curX) -> bool:
            if curX < 0 or curX >= x:
                return False
            if curY < 0 or curY >= y:
                return False
            return True

        def runQueue():
            while q:
                (curY, curX) = q.pop()
                for (dy, dx) in dirChange:
                    if isLegalLoc(curY + dy, curX + dx) and grid[curY + dy][curX + dx] == "1":
                        grid [curY + dy][curX + dx] = "2"
                        q.append((curY + dy, curX + dx))


        for curY in range(y):
            for curX in range(x):
                if grid[curY][curX] == "1":
                    q.append((curY, curX))
                    islandCount += 1
                    runQueue()
        return islandCount

