/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        st.push(root);
        
        while(true) {
            if(st.top()!=NULL) {
                st.push(st.top()->left);
            } else {
                st.pop();
                if(--k==0) return st.top()->val;
                TreeNode *curr = st.top();
                st.pop();
                st.push(curr->right);                
            }
        }
        
        return root->val;
    }
};