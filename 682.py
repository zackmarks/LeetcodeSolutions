"""
682. Baseball Game
https://leetcode.com/problems/baseball-game/
Skills: Stacks
"""

class Solution:
    def calPoints(self, operations: List[str]) -> int:
        scores = []

        for op in operations:
            if op == '+':
                a = scores.pop()
                b = scores.pop()
                scores.append(b)
                scores.append(a)
                scores.append(a+b)
            elif op == 'D':
                a = scores.pop()
                scores.append(a)
                scores.append(2*a)
            elif op == 'C':
                scores.pop()
            else:
                scores.append(int(op))
        
        score = 0
        for val in scores:
            score += val
        return score

