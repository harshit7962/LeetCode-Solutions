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
    ListNode* rotateRight(ListNode* head, int k) {
        int num_nodes = 0;
        for(ListNode *curr=head;curr!=NULL;curr=curr->next) {
            num_nodes++;
        }
        
        if(num_nodes == 0) return NULL;
        k = k%num_nodes;
        
        if(k == 0) return head;
        
        ListNode *start = head, *curr=head;
        while(k>0) {curr = curr->next; k--;}
        
        while(curr->next!=NULL) {
            curr = curr->next;
            start = start->next;
        }
        
        curr->next = head;
        head = start->next;
        start->next = NULL;
        
        return head;
        
    }
};