/*
1367. Linked List in Binary Tree
https://leetcode.com/problems/linked-list-in-binary-tree/description/
Skills: DFS, Trees, Linked Lists
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */




class Solution {
private:
    bool helper(ListNode* head, TreeNode* root, ListNode* falseHead){
        if(head == NULL){ 
            return true;
        }
        if(root == NULL){
            return false;
        }
            
        if(helper(head->next, root->left, falseHead) || helper(head->next, root->right, falseHead)) return true;
        if(head->val == root->val){
            if (helper(falseHead->next->next, root->left, falseHead) || helper(falseHead->next->next, root->right, falseHead)) return true;
        }
        return false;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        ListNode* falseHead = new ListNode(0,head);
        return helper(head, root, falseHead);
    }
};

