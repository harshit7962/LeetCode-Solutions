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
private:
    TreeNode *res,*curr;
public:
    void inorder(TreeNode *root) {
        
        if(root!=NULL) {
            inorder(root->left);
            if(res==NULL) {curr=root;res=root;}
            else {root->left=NULL;curr->right = root; curr=curr->right;}
            inorder(root->right);
        }
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return res;
    }
};