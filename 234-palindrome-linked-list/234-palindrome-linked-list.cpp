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
    bool isPalindrome(ListNode* head) {
        string str="";
        for(ListNode* curr=head;curr!=NULL;curr=curr->next) str+=(curr->val+48);
        
        int start=0, end=str.size()-1;
        if(end==0 || end==-1) return true;
        
        while(start<end) {
            if(str[start]!=str[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};