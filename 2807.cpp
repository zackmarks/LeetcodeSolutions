/*
2807. Insert Greatest Common Divisors in Linked List
https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/
Skills: Linked List, algorithms
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
private:
    int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* iterator = head;
        while(iterator->next){
            int numA = iterator->val;
            int numB = iterator->next->val;
            int newGCD = gcd(numA, numB);
            ListNode* insertedNode = new ListNode(newGCD, iterator->next);
            iterator->next = insertedNode;
            iterator = iterator->next->next;

        }
        return head;
    }
};