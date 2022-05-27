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
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        ListNode *curr=NULL, *hd;
        int currsum=0;
        while(head!=NULL) {
            currsum+=head->val;
            if(head->val==0) {
                ListNode* temp = new ListNode(currsum);
                if(curr==NULL) {
                    curr = temp;
                    hd = curr;
                } else {
                    curr->next = temp;
                    curr = curr->next;
                }
                currsum=0;
            }
            head=head->next;
        }
        return hd;
    }
};