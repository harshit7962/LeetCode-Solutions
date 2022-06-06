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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count1=0, count2=0;
        for(ListNode *curr=headA;curr!=NULL;curr=curr->next) count1++;
        for(ListNode *curr=headB;curr!=NULL;curr=curr->next) count2++;
        
        while(count1>count2) {
            headA = headA->next;
            count1--;
        }
        
        while(count2>count1) {
            headB = headB->next;
            count2--;
        }
        
        while(headA!=headB) {headA=headA->next; headB=headB->next;}
        
        return headA;
    }
};