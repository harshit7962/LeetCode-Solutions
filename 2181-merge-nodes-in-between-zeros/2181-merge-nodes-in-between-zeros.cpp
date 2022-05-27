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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *curr=head;
        ListNode *temp=head->next;
        
        while(temp!=NULL) {
            if(temp->val!=0) {
                curr->val+=temp->val;
                temp = temp->next;
                curr->next = temp;
            } else if(temp->next!=NULL) {
                curr = curr->next;
                temp = temp->next;
            } else {
                curr->next = NULL;
                temp=NULL;
            }
        }
        
        return head;
    }
};