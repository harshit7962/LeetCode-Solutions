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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL) return {};
        
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            int c = q.size();
            vector<int> temp;
            for(int i=0;i<c;i++) {
                TreeNode *curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
            res.push_back(temp);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};