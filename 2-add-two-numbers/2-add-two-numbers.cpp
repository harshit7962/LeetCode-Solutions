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
        ListNode *res=NULL, *l3;
        
        int carry=0;
        
        while(l1!=NULL || l2!=NULL) {
            int sum = carry;
            if(l1!=NULL) {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL) {
                sum+=l2->val;
                l2=l2->next;
            }
            
            carry=sum/10;
            
            ListNode *temp = new ListNode(sum%10);
            if(res==NULL) {
                res=temp;
                l3 = res;
            } else {
                l3->next = temp;
                l3 = l3->next;
            }
        }
        
        if(carry>0) {
            ListNode *temp = new ListNode(carry);
            l3->next = temp;
        }

        return res;
    }
};