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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr = head, *prev = head;
        //Move to the nth node from begining
        for(int i=0;i<n;i++) curr = curr->next;
        
        //If curr is null, it implies we need to delete the head node
        if(curr==NULL) return head->next;
        
        //Move from beginning using another pointer and stop when initial pointer reaches null
        while(curr->next!=NULL) {curr=curr->next; prev=prev->next;}
        
        prev->next = prev->next->next;
        return  head;
    }
};