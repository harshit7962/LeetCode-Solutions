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
    bool hasPathSum(TreeNode* root, int targetSum, int currsum=0) {
        if(root==NULL) return false;
        currsum+=root->val;
        if(root->left==NULL && root->right==NULL) {
            if(targetSum == currsum) return true;
            return false;
        }
        
        return hasPathSum(root->left, targetSum, currsum) || hasPathSum(root->right, targetSum, currsum);
    }
};