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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> v;
        
        for(ListNode *curr=head;curr!=NULL;curr=curr->next) {
            v.push_back(curr->val);
        }
        
        swap(v[k-1], v[v.size()-k]);
        
        int i=0;
        for(ListNode *curr=head;curr!=NULL;curr=curr->next) {
            curr->val = v[i++];
        }
        
        return head;
    }
};