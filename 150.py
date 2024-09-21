"""
150. Evaluate Reverse Polish Notation
https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
Skills: Stacks, Algorithms

"""


class Solution:
    def isNum(self, t: str) -> bool:
        if t == '+' or t == '-' or t == '*' or t == '/':
            return False
        return True

    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if self.isNum(token): #error here
                stack.append(int(token))
            else:
                a = stack.pop()
                b = stack.pop()
                if token == '+':
                    stack.append(a+b)
                elif token == '-':
                    stack.append(b-a)
                elif token == '*':
                    stack.append(a*b)
                else:
                    stack.append(int(b/a))
        return stack[-1]

        