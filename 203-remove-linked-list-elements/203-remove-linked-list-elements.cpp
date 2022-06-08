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
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL && head->val==val) head=head->next;
        if(head==NULL) return head;
        
        ListNode *curr=head;
        
        while(curr!=NULL && curr->next!=NULL) {
            while(curr->next!=NULL && curr->next->val==val) curr->next = curr->next->next;
            curr = curr->next;
        }
        
        return head;
    }
};