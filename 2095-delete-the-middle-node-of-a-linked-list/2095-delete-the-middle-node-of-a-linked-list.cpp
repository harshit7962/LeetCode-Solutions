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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) {
            delete head;
            return NULL;
        }
        
        ListNode *slow=head, *fast=head;
        
        
        while(fast->next!=NULL && fast->next->next!=NULL) {
            fast=fast->next->next;
            if(fast!=NULL && fast->next==NULL) break;
            slow=slow->next;
        }
        
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return head;
    }
};