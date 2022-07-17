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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> res;
        bool leftright = true;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()) {
            stack<TreeNode *> st;
            int c = q.size();
            vector<int> temp;
            
            for(int i=0;i<c;i++) {
                TreeNode *curr = q.front();
                q.pop();
                
                temp.push_back(curr->val);
                
                if(!leftright) {
                    if(curr->right!=NULL) st.push(curr->right);
                    if(curr->left!=NULL) st.push(curr->left);
                } else {
                    if(curr->left!=NULL) st.push(curr->left);
                    if(curr->right!=NULL) st.push(curr->right);
                }
            }
            leftright = !leftright;
            
            while(!st.empty()) {
                q.push(st.top());
                st.pop();
            }
            
            res.push_back(temp);
        }
        
        return res;
    }
};