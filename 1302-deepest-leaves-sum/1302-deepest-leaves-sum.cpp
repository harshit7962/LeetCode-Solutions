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
    int sum=0, max_height=0;
    
    void inOrderTraversal(TreeNode* root, int height=0) {
        if(root->left!=NULL) inOrderTraversal(root->left, height+1);
        if(root->right!=NULL) inOrderTraversal(root->right, height+1);
        
        if(height>max_height) {
            sum=root->val;
            max_height=height;
        } else if(height==max_height) sum+=root->val;
        
    }
    
    int deepestLeavesSum(TreeNode* root) {
        inOrderTraversal(root);
        return sum;
    }
};