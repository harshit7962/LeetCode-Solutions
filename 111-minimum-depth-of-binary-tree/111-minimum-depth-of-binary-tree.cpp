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
    int res=INT_MAX;
    int minDepth(TreeNode* root, int depth=1) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return min(res, depth);
        else if(root->left==NULL) return minDepth(root->right, depth+1);
        else if(root->right==NULL) return minDepth(root->left, depth+1);
        
        return min(minDepth(root->left, depth+1), minDepth(root->right, depth+1));
    }
};