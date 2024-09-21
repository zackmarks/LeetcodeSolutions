/*
83. Remove Duplicates from Sorted List
https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
Skills: Linked List, Pointers
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        int prevVal = head->val;
        ListNode* i1 = head;
        ListNode* i2 = head->next;
        while(i2){
            if(i2->val == prevVal){
                i2 = i2->next;
                i1->next = i2;
            }else{
                prevVal = i2->val;
                i2 = i2->next;
                i1 = i1->next;
            }
        }
        return head;
    }
};

