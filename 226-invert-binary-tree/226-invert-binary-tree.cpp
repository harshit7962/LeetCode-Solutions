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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        if(root->left==NULL) {
            root->left = invertTree(root->right);
            root->right = NULL;
        }
        else if(root->right==NULL) {
            root->right = invertTree(root->left);
            root->left = NULL;
        } else {
            TreeNode *temp = invertTree(root->left);
            root->left = invertTree(root->right);
            root->right = temp;
        }
        return root;
    }
};