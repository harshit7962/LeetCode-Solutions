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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        long long res=0;
        long long lv=0, rv=0;
        while(!q.empty()) {
            int c = q.size();
            lv = q.front().second;
            for(int i=0;i<c;i++) {
                TreeNode *curr = q.front().first;
                rv = q.front().second;
                q.pop();
                if(curr->left!=NULL) q.push({curr->left, rv*2+1});
                if(curr->right!=NULL) q.push({curr->right, rv*2+2});
            }
            res = max(res, rv-lv+1);
        }
        
        
        return res;
    }
};