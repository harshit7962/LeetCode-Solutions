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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head, *prevFirst = head;
        bool isFirstPass = true;
        
        while(curr!=NULL) {
            ListNode *prev = NULL, *first = curr, *temp = curr;
            int count = 0;
            
            while(temp!=NULL && count<k) {
                temp = temp->next;
                count++;
            }
            
            if(count<k) {prevFirst->next = curr; break;}
            
            count = 0;
            
            while(curr!=NULL && count<k) {
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }
            
            if(isFirstPass) {
                isFirstPass = false;
                head = prev;
            } else prevFirst->next = prev;
            
            prevFirst = first;
        }
        
        return head;
    }
};