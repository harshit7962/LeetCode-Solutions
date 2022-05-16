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
    ListNode* middleNode(ListNode* head) {
        ListNode *l1=head, *l2=head;
        
        while(l2->next!=NULL) {
            l1 = l1->next;
            if(l2->next->next!=NULL) l2 = l2->next->next;
            else break;
        }
        return l1;
    }
};