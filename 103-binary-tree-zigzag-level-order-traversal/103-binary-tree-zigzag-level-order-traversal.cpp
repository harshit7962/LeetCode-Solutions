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
        
        stack<TreeNode *> s1, s2;
        s1.push(root);
        
        vector<vector<int>> res;
        
        while(!s1.empty() || !s2.empty()) {
            vector<int> temp1, temp2;
            if(!s1.empty()) {
                while(!s1.empty()) {
                    TreeNode *curr = s1.top();
                    s1.pop();
                    if(curr->left!=NULL) s2.push(curr->left);
                    if(curr->right!=NULL) s2.push(curr->right);
                    
                    temp1.push_back(curr->val);
                }
                res.push_back(temp1);
            }
            
            if(!s2.empty()) {
                while(!s2.empty()) {
                    TreeNode *curr = s2.top();
                    s2.pop();
                    if(curr->right!=NULL) s1.push(curr->right);
                    if(curr->left!=NULL) s1.push(curr->left);
                    
                    temp2.push_back(curr->val);
                }
                res.push_back(temp2);
            }
        }
        
        
        return res;
    }
};