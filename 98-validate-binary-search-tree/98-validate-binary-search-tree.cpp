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
    bool isValidBST(TreeNode* root, long left=(long)INT_MIN-1, long right=(long)INT_MAX+1) {
        if(root == NULL) return true;
        if(root->val>=right || root->val<=left) return false;
        
        return isValidBST(root->left, left, root->val) && isValidBST(root->right, root->val, right);
    }
};