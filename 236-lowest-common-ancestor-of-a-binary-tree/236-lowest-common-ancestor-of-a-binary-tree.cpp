/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root;
        if(root == p || root == q) return root;
        
        TreeNode *lcal = lowestCommonAncestor(root->left, p, q);
        TreeNode *lcar = lowestCommonAncestor(root->right, p, q);
        
        if(lcal != NULL && lcar != NULL) return root;
        else if(lcal == NULL) return lcar;
        return lcal;
    }
};