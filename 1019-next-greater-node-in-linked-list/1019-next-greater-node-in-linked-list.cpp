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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<pair<int, int>> st;
        int i=0;
        st.push({head->val, i});
        res.push_back(0);
        
        head = head->next;
        while(head!=NULL) {
            while(!st.empty() && head->val > st.top().first) {
                res[st.top().second] = head->val;
                st.pop();
            }
            i++;
            res.push_back(0);
            st.push({head->val, i});
            head = head->next;
        }
        
        return res;
    }
};