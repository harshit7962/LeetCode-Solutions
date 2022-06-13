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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            int x = q.size();
            for(int i=0;i<x;i++) {
                TreeNode *temp = q.front();
                q.pop();
                if(i==0) res.push_back(temp->val);
                if(temp->right!=NULL) q.push(temp->right);
                if(temp->left!=NULL) q.push(temp->left);
            }
        }
        
        return res;
    }
};