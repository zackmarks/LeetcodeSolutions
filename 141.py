"""
141. Linked List Cycle
https://leetcode.com/problems/linked-list-cycle/description/
Skills: Linked List, Two Pointer, Cycles, ALgorithms
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head == None:
            return False
        fast = head.next
        slow = head
        while fast and fast.next:
            if fast == slow:
                return True
            fast = fast.next.next
            slow = slow.next
        return False

