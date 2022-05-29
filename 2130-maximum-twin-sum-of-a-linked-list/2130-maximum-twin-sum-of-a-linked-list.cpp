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
    int pairSum(ListNode* head) {
        ListNode *middle=head, *tail=head;
        
        while(tail->next!=NULL && tail->next->next!=NULL) {
            middle = middle->next;
            tail = tail->next->next;
        }
        
        ListNode *curr=middle->next, *prev=middle;
        while(curr!=NULL) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        middle->next->next = NULL;
        middle->next = prev;
        middle = middle->next;
        
        int res=0;
        while(middle!=NULL) {
            res = max(res, head->val + middle->val);
            head = head->next;
            middle = middle->next;
        }
        
        return res;
    }
};