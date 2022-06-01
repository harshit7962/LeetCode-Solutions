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
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        if(root->left==NULL && root->right==NULL) {
            res.push_back(root->val);
            return res;
        }
        if(root->left!=NULL)
        postorderTraversal(root->left);
        if(root->right!=NULL)
        postorderTraversal(root->right);
        res.push_back(root->val);
        return res;
    }
};