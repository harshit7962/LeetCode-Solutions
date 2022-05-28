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
    ListNode* removeElements(ListNode* head, int val) {
        
        
        while(head!=NULL && head->val==val) {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
        
        if(head==NULL) return NULL;
        
        ListNode *ptr = head;
        while(ptr->next!=NULL) {
            if(ptr->next->val==val) {
                ListNode *temp = ptr->next;
                ptr->next = ptr->next->next;
                delete temp;
            } else {
                ptr=ptr->next;
        
            }
        }
        return head;
    }
};