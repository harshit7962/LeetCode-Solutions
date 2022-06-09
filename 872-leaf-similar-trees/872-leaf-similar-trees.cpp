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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1=leafs(root1), leaf2=leafs(root2);
        
        return leaf1==leaf2;
    }
    
    vector<int> leafs(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode *curr = st.top();
            st.pop();
            
            if(curr->left==NULL && curr->right==NULL) res.push_back(curr->val);
            
            if(curr->right!=NULL) st.push(curr->right);
            if(curr->left!=NULL) st.push(curr->left);
        }
        
        return res;
    }
};