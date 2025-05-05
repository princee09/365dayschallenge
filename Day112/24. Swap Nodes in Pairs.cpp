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
    ListNode* swapPairs(ListNode* head) {
        // Dummy node points to head, simplifies edge cases
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Traverse the list in pairs
        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swapping nodes by reassigning pointers
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev pointer two nodes ahead for next swap
            prev = first;
        }

        // New head is dummy.next
        return dummy.next;
    }
};