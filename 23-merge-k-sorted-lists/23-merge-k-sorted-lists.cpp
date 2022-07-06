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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return {};
        if(lists.size()==1) return lists[0];
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        
        //Priority Queue generation of first elements of each list
        for(int i=0;i<lists.size();i++) {
            if(lists[i]!=NULL)
                pq.push({lists[i]->val, lists[i]});
        }
        
        if(pq.size()==0) return {};
        
        
        //Initialization of new list
        int x = pq.top().first;
        ListNode *temp = pq.top().second;
        pq.pop();
        ListNode *head = new ListNode(x);
        
        if(temp->next!=NULL) pq.push({temp->next->val, temp->next});
        
        ListNode *curr = head;
        
        while(!pq.empty()) {
            x = pq.top().first;
            temp = pq.top().second;
            pq.pop();
            
            curr->next = temp;
            curr = curr->next;
            
            if(temp->next!=NULL) pq.push({temp->next->val, temp->next});
        }
        
        return head;
    }
};