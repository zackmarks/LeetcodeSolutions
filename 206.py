"""
206. Reverse Linked List
https://leetcode.com/problems/reverse-linked-list/description/
Skills: Linked List, Pointers, Algorithm
"""


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return head
        b = head
        a = head.next
        c = None

        while(a):
            b.next = c
            c = b
            b = a
            a = a.next
            b.next = c
        return b

