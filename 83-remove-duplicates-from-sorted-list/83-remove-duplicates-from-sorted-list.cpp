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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode *curr = head;
        
        while(curr!=NULL) {
            while(curr->next!=NULL && curr->next->val==curr->val) curr->next = curr->next->next;
            curr = curr->next;
        }
        
        return head;
    }
};