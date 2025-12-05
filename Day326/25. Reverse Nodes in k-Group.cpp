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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || !head) return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* prevGroupEnd = dummy;
        ListNode* curr = head;
        while (curr) {
            ListNode* groupStart = curr;
            int count = 0;
            while (curr && count < k) {
                curr = curr->next;
                count++;
            }
            if (count == k) {
                ListNode* prev = nullptr;
                ListNode* temp = groupStart;
                for (int i = 0; i < k; i++) {
                    ListNode* nextNode = temp->next;
                    temp->next = prev;
                    prev = temp;
                    temp = nextNode;
                }
                prevGroupEnd->next = prev;
                groupStart->next = curr;
                prevGroupEnd = groupStart;
            } else {
                prevGroupEnd->next = groupStart;
            }
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};