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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) 
            return head;               
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }
        // curr points to first node of the segment to be reversed
        ListNode* curr = prev->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = curr->next;       // node to move
            curr->next = temp->next;           // detach temp
            temp->next = prev->next;           // insert temp right after prev
            prev->next = temp;                 
        }

        return dummy.next;
    }
};