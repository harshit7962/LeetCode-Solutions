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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *start = list1, *end = NULL;
        
        for(int i=0;i<a-1;i++) start = start->next;
        
        end = start;
        for(int i=a;i<=b+1;i++) end = end->next;
        
        start->next = list2;
        while(start->next!=NULL) start=start->next;
        
        start->next = end;
        
        return list1;
    }
};