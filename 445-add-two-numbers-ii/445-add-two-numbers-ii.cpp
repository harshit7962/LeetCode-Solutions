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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        for(ListNode *curr=l1;curr!=NULL;curr=curr->next) st1.push(curr->val);
        for(ListNode *curr=l2;curr!=NULL;curr=curr->next) st2.push(curr->val);
        
        ListNode *curr=NULL, *temp=NULL;
        int c=0;
        while(!st1.empty() || !st2.empty()) {
            int x=c;
            if(!st1.empty()) {x+=st1.top();st1.pop();}
            if(!st2.empty()) {x+=st2.top();st2.pop();}
            c=x/10;
            x=x%10;
            temp = new ListNode(x);
            if(curr == NULL) {curr=temp;}
            else {temp->next = curr; curr=temp;}
        }
        if(c==1) {temp = new ListNode(c); temp->next=curr;}
        
        return temp;
    }
};