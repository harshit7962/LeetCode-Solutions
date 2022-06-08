/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        
        ListNode *fast=head, *slow=head;
        
        do {
            fast = fast->next->next;
            slow = slow->next;
            if(slow==fast) return true;
        } while(fast!=NULL && fast->next!=NULL);
        
        return false;
    }
};