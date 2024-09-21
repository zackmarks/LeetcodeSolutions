/*
725. Split Linked List in Parts
https://leetcode.com/problems/split-linked-list-in-parts/description/
Skills: Linked List, Pointers, Algorithms
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* iterator = head;
        int nodeCount = 0;
        while(iterator){
            nodeCount++;
            iterator = iterator->next;
        }

        vector<ListNode*> retVec(k, nullptr);

        int nodesPerPart = nodeCount / k;
        int remainder = nodeCount % k;

        iterator = head;
        int toFill = 0;


        while(iterator){
            retVec[toFill] = iterator;
            int leftThisPart = nodesPerPart - 1 + (remainder > 0);
            remainder--;
            while(leftThisPart > 0 && iterator){
                leftThisPart--;
                iterator = iterator->next;
            }
            if(iterator){
                ListNode* temp = iterator->next;
                iterator->next = nullptr;
                iterator = temp;
            }
            toFill++;
        }

        return retVec;
    }
};

