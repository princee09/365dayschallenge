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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* nodeToRemove = slow->next;
        slow->next = nodeToRemove->next;
        
        
        return dummy.next;
    }
};
