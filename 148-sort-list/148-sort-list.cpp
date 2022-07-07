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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(l2==NULL) return l1;
        if(l1==NULL) return l2;
        
        ListNode *head=NULL, *curr=NULL;
        
        while(l1!=NULL && l2!=NULL) {
            if(l1->val < l2->val) {
                if(head==NULL) {
                    head = l1;
                    curr = head;
                } else {
                    curr->next = l1;
                    curr = curr->next;
                }
                l1 = l1->next;
            } else {
                if(head == NULL) {
                    head = l2;
                    curr = head;
                } else {
                    curr->next = l2;
                    curr = curr->next;
                }
                l2 = l2->next;
            }
        }
        
        if(l1!=NULL) curr->next = l1;
        else curr->next = l2;
        
        return head;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        
        
        ListNode *mid = head, *tail = head;
        
        while(tail->next!=NULL && tail->next->next!=NULL) {
            mid = mid->next;
            tail = tail->next->next;
        }
        
        ListNode *right = mid->next;
        mid->next = NULL;
        
        ListNode *l = sortList(head);
        ListNode *r = sortList(right);
        
        return merge(l, r);
    }
};