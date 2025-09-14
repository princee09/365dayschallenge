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
        int n = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        int partSize = n / k;
        int remainder = n % k;

        vector<ListNode*> parts(k, nullptr);
        ListNode* curr = head;
        for (int i = 0; i < k && curr != nullptr; i++) {
            parts[i] = curr;
            int currentPartSize = partSize + (remainder > 0 ? 1 : 0);
            remainder--;

            for (int j = 0; j < currentPartSize - 1; j++) {
                curr = curr->next;
            }

            ListNode* next = curr->next;
            curr->next = nullptr;
            curr = next;
        }

        return parts;
    }
};