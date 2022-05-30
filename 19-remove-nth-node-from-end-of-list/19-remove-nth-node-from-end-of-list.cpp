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
        ListNode *curr1=head, *curr2=head;
        for(int i=1;i<=n;i++) curr1=curr1->next;
        
        if(curr1==NULL) {
            head = head->next;
            return head;
        }
        
        while(curr1->next!=NULL) {
            curr1=curr1->next;
            curr2=curr2->next;
        }
        
        curr2->next = curr2->next->next;
        
        return head;
    }
};