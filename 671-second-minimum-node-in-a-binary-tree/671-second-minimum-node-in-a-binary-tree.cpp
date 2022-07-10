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
    int findSecondMinimumValue(TreeNode* root) {
        if(root->left==NULL) return -1;
        
        if(root->left->val == root->right->val) {
            int l = findSecondMinimumValue(root->left);
            int r = findSecondMinimumValue(root->right);
            if(l==-1) return r;
            if(r==-1) return l;
            
            return min(l, r);
        } else if(root->left->val < root->right->val) {
            int l = findSecondMinimumValue(root->left);
            if(l==-1) return root->right->val;
            return min(l, root->right->val);
        }
        
        int r = findSecondMinimumValue(root->right);
        if(r==-1) return root->left->val;
        return min(r, root->left->val);
    }
};