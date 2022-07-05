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
        if(root == NULL) return {};
        
        vector<vector<int>> res;
        
        queue<TreeNode *> q;
        q.push(root);
        
        bool lToR = true;
        
        while(!q.empty()) {
            stack<TreeNode *> st;
            int c = q.size();
            vector<int> curr;
            for(int i=0;i<c;i++) {
                TreeNode *temp = q.front();
                q.pop();
                
                curr.push_back(temp->val);
                
                if(lToR) {
                    if(temp->left!=NULL) st.push(temp->left);
                    if(temp->right!=NULL)st.push(temp->right);
                } else {
                    if(temp->right!=NULL)st.push(temp->right);
                    if(temp->left!=NULL) st.push(temp->left);
                }
            }
            
            lToR = !lToR;
            
            while(!st.empty()) {
                q.push(st.top());
                st.pop();
            }
            
            res.push_back(curr);
        }
        
        return res;
    }
};