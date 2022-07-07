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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head, *temp = NULL, *newhead = NULL;
        bool isRepeating = false;
        
        while(curr!=NULL) {
            
            while(curr->next!=NULL && curr->val == curr->next->val) {
                isRepeating = true;
                curr = curr->next;
            }
            
            if(!isRepeating) {
                if(temp==NULL) {newhead = curr; temp = curr;}
                else { 
                    temp->next = curr;
                    temp = temp->next;
                }
            }
            
            isRepeating = false;
            curr = curr->next;
        }
        
        if(temp==NULL) return temp;
        
        temp->next = NULL;
        return newhead;
    }
};