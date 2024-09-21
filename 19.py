"""
19. Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
Skills: Linked Lists
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        it = head
        count = 0
        while(it):
            count += 1
            it = it.next
        
        if count <= 1:
            return None
        removeNext = count - n 
        if removeNext == 0:
            return head.next
        
        it = head
        for i in range(removeNext-1):
            it = it.next
        
        it.next = it.next.next

        return head

