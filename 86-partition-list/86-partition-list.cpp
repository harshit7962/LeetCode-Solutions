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
    ListNode* partition(ListNode* head, int x) {
        ListNode *before = NULL, *after = NULL;
        ListNode *bfhead = NULL, *ahead = NULL;
        
        for(ListNode *curr = head;curr!=NULL;curr=curr->next) {
            if(curr->val < x) {
                if(bfhead == NULL) {
                    bfhead = curr;
                    before = curr;
                } else {
                    before->next = curr;
                    before = curr;
                }
            } else {
                if(ahead == NULL) {
                    ahead = curr;
                    after = curr;
                } else {
                    after->next = curr;
                    after = curr;
                }
            }
        }
        
        if(bfhead == NULL) return ahead;
        if(ahead == NULL) return bfhead;
        
        before->next = ahead;
        after->next = NULL;
        
        return bfhead;
    }
};