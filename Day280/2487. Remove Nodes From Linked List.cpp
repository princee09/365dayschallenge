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
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        
        ListNode* curr = head;
        ListNode* maxNode = head;
        ListNode* temp = head;
        
        while (curr && curr->next) {
            if (curr->next->val < maxNode->val) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
                maxNode = curr;
            }
        }
        return reverseList(temp);
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        
        return prev;
    }
};