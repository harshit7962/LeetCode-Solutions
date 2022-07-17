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
    int res = INT_MIN;
    
    int traversal(TreeNode* root) {
        int leftsum = -1, rightsum = -1;
        if(root->left!=NULL) leftsum = traversal(root->left);
        if(root->right!=NULL) rightsum = traversal(root->right);
        
        int total = root->val;
        if(leftsum>0) total += leftsum;
        if(rightsum>0) total += rightsum;
        
        res = max(res, total);
        
        return max(max(leftsum, rightsum) + root->val, root->val);
    }
    
    
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        traversal(root);
        return res;
    }
};