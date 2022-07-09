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
    int res=0;
    void currSum(TreeNode *root,long long curr, int targetSum) {
        if(root == NULL) return;
        
        curr+=root->val;
        
        if(curr == targetSum) res++;
        
        currSum(root->left, curr, targetSum);
        currSum(root->right, curr, targetSum);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        currSum(root, 0, targetSum);
        if(root->left) pathSum(root->left, targetSum);
        if(root->right) pathSum(root->right, targetSum);
        
        return res;
    }
};