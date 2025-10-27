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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;       
        ListNode* prevGroupEnd = dummy;
        int groupNum = 1;      
        while (prevGroupEnd->next) {
            int count = 0;
            ListNode* curr = prevGroupEnd->next;     
            while (curr && count < groupNum) {
                count++;
                curr = curr->next;
            }
            if (count % 2 == 0) {
                prevGroupEnd = reverseList(prevGroupEnd, count);
            } else {
                for (int i = 0; i < count; i++) {
                    prevGroupEnd = prevGroupEnd->next;
                }
            }            
            groupNum++;
        }       
        return dummy->next;
    }
    
private:
    ListNode* reverseList(ListNode* prev, int count) {
        if (count <= 1) return prev->next;
        
        ListNode* curr = prev->next;
        ListNode* nextNode = curr->next;
        for (int i = 0; i < count - 1; i++) {
            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
            nextNode = curr->next;
        }
        
        return curr;
    }
};