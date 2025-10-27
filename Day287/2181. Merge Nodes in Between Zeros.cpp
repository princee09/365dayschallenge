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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* modify = head;
        ListNode* curr = head->next;
        
        while (curr) {
            if (curr->val == 0) {
                if (curr->next) {
                    modify = modify->next;
                    modify->val = 0; 
                }
            } else {
                modify->val += curr->val;
            }
            curr = curr->next;
        }
        modify->next = nullptr;
        
        return head;
    }
};