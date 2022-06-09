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
    bool isUnivalTree(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return true;
        else if(root->left==NULL) return (root->right->val == root->val) && isUnivalTree(root->right);
        else if(root->right==NULL) return (root->left->val == root->val) && isUnivalTree(root->left);
        return (root->left->val==root->val) && (root->right->val==root->val) && isUnivalTree(root->left) && isUnivalTree(root->right);
        
    }
};