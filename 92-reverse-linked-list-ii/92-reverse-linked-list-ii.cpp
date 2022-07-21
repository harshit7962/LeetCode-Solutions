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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        
        ListNode *curr=head, *prevL=NULL;
        int num_nodes = right-left;
        while(left>1) {
            prevL = curr;
            curr = curr->next;
            left--;
        }
        
        ListNode *next = curr->next;
        ListNode *prev = NULL;
        while(num_nodes>=0) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            num_nodes--;
        }
        
        if(prevL!=NULL) {
            prevL->next->next = next;
            prevL->next = prev;
            return head;
        }
        head->next = curr;
        return prev;
    }
};