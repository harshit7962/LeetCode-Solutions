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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL ||  head->next==NULL) return head;
        
        ListNode *es = NULL, *ee = NULL, *os = NULL, *oe = NULL;
        
        for(ListNode *curr=head;curr!=NULL;curr=curr->next->next) {
            if(os==NULL) {os = curr; oe = curr;}
            else {
                oe->next = curr;
                oe = curr;
            }
            if(curr->next==NULL) break;
            if(es==NULL) {es = curr->next; ee=curr->next;}
            else {
                ee->next = curr->next;
                ee = curr->next;                
            }
        }
        ee->next = NULL;
        oe->next = es;        
        
        return os;
    }
};